#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

// Game constants
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 24;
const int BLOCK_START_X = BOARD_WIDTH / 2;
const int BLOCK_START_Y = 0;
const int INITIAL_SPEED = 500; // milliseconds
const int SPEED_INCREASE = 50;
const int MIN_SPEED = 100;

// Game structures
enum Color {
	COLOR_BLACK_PAIR = 1,
	COLOR_RED_PAIR,
	COLOR_GREEN_PAIR,
	COLOR_YELLOW_PAIR,
	COLOR_BLUE_PAIR,
	COLOR_MAGENTA_PAIR,
	COLOR_CYAN_PAIR,
	COLOR_WHITE_PAIR
};

struct Point {
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct Tetromino {
	std::vector<Point> shape;
	int color;
	int rotation = 0;
	Point position;

	// Constructor for easier initialization
	Tetromino(const std::vector<Point>& _shape = {}, int _color = COLOR_WHITE_PAIR)
		: shape(_shape), color(_color), rotation(0), position(0, 0) {}
};

// Game state
std::vector<std::vector<int>> board(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));
int score = 0;
int level = 1;
int speed = INITIAL_SPEED;
bool gameOver = false;

// Initialize tetrominos separately
std::vector<Tetromino> tetrominos;

void initializeTetrominos() {
	// I
	tetrominos.push_back(Tetromino({{0, 0}, {1, 0}, {2, 0}, {3, 0}}, COLOR_CYAN_PAIR));
	// J
	tetrominos.push_back(Tetromino({{0, 0}, {0, 1}, {1, 1}, {2, 1}}, COLOR_BLUE_PAIR));
	// L
	tetrominos.push_back(Tetromino({{2, 0}, {0, 1}, {1, 1}, {2, 1}}, COLOR_YELLOW_PAIR));
	// O
	tetrominos.push_back(Tetromino({{0, 0}, {1, 0}, {0, 1}, {1, 1}}, COLOR_WHITE_PAIR));
	// S
	tetrominos.push_back(Tetromino({{1, 0}, {2, 0}, {0, 1}, {1, 1}}, COLOR_GREEN_PAIR));
	// T
	tetrominos.push_back(Tetromino({{1, 0}, {0, 1}, {1, 1}, {2, 1}}, COLOR_MAGENTA_PAIR));
	// Z
	tetrominos.push_back(Tetromino({{0, 0}, {1, 0}, {1, 1}, {2, 1}}, COLOR_RED_PAIR));
}

Tetromino currentBlock;
Tetromino nextBlock;

// Function prototypes
void initializeGame();
void draw();
void drawBoard();
void drawBlock(const Tetromino& block, bool isCurrent = false);
void drawNextBlock();
void drawScore();
void createNewBlock();
void moveBlock(int dx, int dy);
void rotateBlock();
bool isValidPosition(const Tetromino& block);
void lockBlock();
void clearLines();
void hardDrop();
void gameLoop();

int main() {
	initializeGame();
	gameLoop();
	endwin();
	return 0;
}

void initializeGame() {
	// Initialize ncurses
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	timeout(100);

	// Initialize colors
	init_pair(COLOR_BLACK_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(COLOR_RED_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_GREEN_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_YELLOW_PAIR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(COLOR_BLUE_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_MAGENTA_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_CYAN_PAIR, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_WHITE_PAIR, COLOR_WHITE, COLOR_BLACK);

	// Seed random number generator
	srand(time(nullptr));

	// Initialize tetrominos
	initializeTetrominos();

	// Initialize game
	createNewBlock();
	nextBlock = tetrominos[rand() % tetrominos.size()];
	nextBlock.position = {BLOCK_START_X, BLOCK_START_Y};
}

void draw() {
	clear();

	// Draw border
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		mvaddch(y + 1, 0, '|');
		mvaddch(y + 1, BOARD_WIDTH * 2 + 1, '|');
	}

	for (int x = 0; x < BOARD_WIDTH * 2 + 2; x++) {
		mvaddch(0, x, '-');
		mvaddch(BOARD_HEIGHT + 1, x, '-');
	}

	drawBoard();
	drawBlock(currentBlock, true);
	drawNextBlock();
	drawScore();

	refresh();
}

void drawBoard() {
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			if (board[y][x] != 0) {
				attron(COLOR_PAIR(board[y][x]));
				mvaddch(y + 1, x * 2 + 1, '[');
				mvaddch(y + 1, x * 2 + 2, ']');
				attroff(COLOR_PAIR(board[y][x]));
			} else {
				mvaddch(y + 1, x * 2 + 1, ' ');
				mvaddch(y + 1, x * 2 + 2, ' ');
			}
		}
	}
}

void drawBlock(const Tetromino& block, bool isCurrent) {
	attron(COLOR_PAIR(block.color));
	for (const auto& p : block.shape) {
		int x = p.x;
		int y = p.y;

		switch (block.rotation) {
			case 0: // 0 degrees
				break;
			case 1: // 90 degrees
				std::swap(x, y);
				y = -y;
				break;
			case 2: // 180 degrees
				x = -x;
				y = -y;
				break;
			case 3: // 270 degrees
				std::swap(x, y);
				x = -x;
				break;
		}

		x += block.position.x;
		y += block.position.y;

		if (y >= 0 && y < BOARD_HEIGHT) {
			mvaddch(y + 1, x * 2 + 1, '[');
			mvaddch(y + 1, x * 2 + 2, ']');
		}
	}
	attroff(COLOR_PAIR(block.color));
}

void drawNextBlock() {
	mvprintw(2, BOARD_WIDTH * 2 + 5, "Next Block:");
	Tetromino displayBlock = nextBlock;
	displayBlock.position = {BOARD_WIDTH + 5, 4};
	drawBlock(displayBlock);
}

void drawScore() {
	mvprintw(10, BOARD_WIDTH * 2 + 5, "Score: %d", score);
	mvprintw(11, BOARD_WIDTH * 2 + 5, "Level: %d", level);

	if (gameOver) {
		mvprintw(BOARD_HEIGHT / 2, (BOARD_WIDTH * 2 - 18) / 2, "Game Over! Press 'r' to restart");
	}
}

void createNewBlock() {
	if (nextBlock.shape.empty()) {
		currentBlock = tetrominos[rand() % tetrominos.size()];
	} else {
		currentBlock = nextBlock;
	}

	currentBlock.position = {BLOCK_START_X, BLOCK_START_Y};
	currentBlock.rotation = 0;

	nextBlock = tetrominos[rand() % tetrominos.size()];
	nextBlock.rotation = 0;

	if (!isValidPosition(currentBlock)) {
		gameOver = true;
	}
}

void moveBlock(int dx, int dy) {
	Tetromino newPos = currentBlock;
	newPos.position.x += dx;
	newPos.position.y += dy;

	if (isValidPosition(newPos)) {
		currentBlock = newPos;
	} else if (dy > 0) {
		lockBlock();
		clearLines();
		createNewBlock();
	}
}

void rotateBlock() {
	Tetromino rotated = currentBlock;
	rotated.rotation = (rotated.rotation + 1) % 4;

	if (isValidPosition(rotated)) {
		currentBlock = rotated;
	} else {
		// Try wall kicks
		for (int offset = 1; offset <= 2; offset++) {
			// Try right
			rotated.position.x = currentBlock.position.x + offset;
			if (isValidPosition(rotated)) {
				currentBlock = rotated;
				return;
			}

			// Try left
			rotated.position.x = currentBlock.position.x - offset;
			if (isValidPosition(rotated)) {
				currentBlock = rotated;
				return;
			}

			// Reset x for next iteration
			rotated.position.x = currentBlock.position.x;
		}
	}
}

bool isValidPosition(const Tetromino& block) {
	for (const auto& p : block.shape) {
		int x = p.x;
		int y = p.y;

		switch (block.rotation) {
			case 0: // 0 degrees
				break;
			case 1: // 90 degrees
				std::swap(x, y);
				y = -y;
				break;
			case 2: // 180 degrees
				x = -x;
				y = -y;
				break;
			case 3: // 270 degrees
				std::swap(x, y);
				x = -x;
				break;
		}

		x += block.position.x;
		y += block.position.y;

		// Check boundaries
		if (x < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT) {
			return false;
		}

		// Check collision with other blocks (only if the block is on the board)
		if (y >= 0 && board[y][x] != 0) {
			return false;
		}
	}

	return true;
}

void lockBlock() {
	for (const auto& p : currentBlock.shape) {
		int x = p.x;
		int y = p.y;

		switch (currentBlock.rotation) {
			case 0:
				break;
			case 1:
				std::swap(x, y);
				y = -y;
				break;
			case 2:
				x = -x;
				y = -y;
				break;
			case 3:
				std::swap(x, y);
				x = -x;
				break;
		}

		x += currentBlock.position.x;
		y += currentBlock.position.y;

		if (y >= 0 && y < BOARD_HEIGHT && x >= 0 && x < BOARD_WIDTH) {
			board[y][x] = currentBlock.color;
		}
	}
}

void clearLines() {
	int linesCleared = 0;

	for (int y = BOARD_HEIGHT - 1; y >= 0; y--) {
		bool lineFull = true;

		for (int x = 0; x < BOARD_WIDTH; x++) {
			if (board[y][x] == 0) {
				lineFull = false;
				break;
			}
		}

		if (lineFull) {
			linesCleared++;

			// Move all lines above down
			for (int yy = y; yy > 0; yy--) {
				for (int x = 0; x < BOARD_WIDTH; x++) {
					board[yy][x] = board[yy - 1][x];
				}
			}

			// Clear the top line
			for (int x = 0; x < BOARD_WIDTH; x++) {
				board[0][x] = 0;
			}

			// Check the same line again (since we moved everything down)
			y++;
		}
	}

	if (linesCleared > 0) {
		score += linesCleared * linesCleared * 100;

		if (score / 1000 >= level) {
			level++;
			speed = std::max(MIN_SPEED, INITIAL_SPEED - (level - 1) * SPEED_INCREASE);
		}
	}
}

void hardDrop() {
	while (true) {
		Tetromino newPos = currentBlock;
		newPos.position.y += 1;

		if (!isValidPosition(newPos)) {
			break;
		}

		currentBlock = newPos;
	}

	lockBlock();
	clearLines();
	createNewBlock();
}

void gameLoop() {
	auto lastFall = std::chrono::steady_clock::now();

	while (true) {
		draw();

		int key = getch();

		if (gameOver) {
			if (key == 'r' || key == 'R') {
				// Reset game
				board = std::vector<std::vector<int>>(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));
				score = 0;
				level = 1;
				speed = INITIAL_SPEED;
				gameOver = false;
				createNewBlock();
			} else if (key == 'q' || key == 'Q') {
				break;
			}
			continue;
		}

		switch (key) {
			case KEY_LEFT:
				// Left arrow moves left
				moveBlock(-1, 0);
				break;
			case KEY_RIGHT:
				// Right arrow moves right
				moveBlock(1, 0);
				break;
			case KEY_DOWN:
				// Down arrow accelerates drop
				moveBlock(0, 1);
				break;
			case KEY_UP:
				// Up arrow rotates
				rotateBlock();
				break;
			case ' ':
				// Space for hard drop
				hardDrop();
				break;
			case 'p':
			case 'P':
				// Pause
				mvprintw(BOARD_HEIGHT / 2, (BOARD_WIDTH * 2 - 12) / 2, "Game Paused");
				refresh();
				timeout(-1); // Wait indefinitely for input
				getch();
				timeout(100);
				break;
			case 'q':
			case 'Q':
				return;
			default:
				break;
		}

		auto currentTime = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFall).count();

		if (elapsed > speed) {
			moveBlock(0, 1);
			lastFall = currentTime;
		}
	}
}
