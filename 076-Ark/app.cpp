// Original is: https://raw.githubusercontent.com/SuperV1234/Tutorials/master/DiveIntoC%2B%2B11/2_Arkanoid/p5.cpp
#include <cmath>
#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f}, ballVelocity{0.8f};
constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{0.6f};
constexpr float blockWidth{60.f}, blockHeight{20.f};
constexpr int countBlocksX{11}, countBlocksY{4};
constexpr float ftStep{1.f}, ftSlice{1.f};

struct Ball {
	CircleShape shape;
	Vector2f velocity{-ballVelocity, -ballVelocity};

	Ball(float mX, float mY) {
		shape.setPosition(mX, mY);
		shape.setRadius(ballRadius);
		shape.setFillColor(Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}

	void update(float mFT) {
		shape.move(velocity * mFT);
		if(left() < 0) velocity.x = ballVelocity;
		else if(right() > windowWidth) velocity.x = -ballVelocity;
		if(top() < 0) velocity.y = ballVelocity;
		else if(bottom() > windowHeight) velocity.y = -ballVelocity;
	}

	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float left() const noexcept { return x() - shape.getRadius(); }
	float right() const noexcept { return x() + shape.getRadius(); }
	float top() const noexcept { return y() - shape.getRadius(); }
	float bottom() const noexcept { return y() + shape.getRadius(); }
};

struct Rectangle {
	RectangleShape shape;
	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float left() const noexcept { return x() - shape.getSize().x / 2.f; }
	float right() const noexcept { return x() + shape.getSize().x / 2.f; }
	float top() const noexcept { return y() - shape.getSize().y / 2.f; }
	float bottom() const noexcept { return y() + shape.getSize().y / 2.f; }
};

struct Paddle : public Rectangle {
	float yPos;

	Paddle(float mX, float mY) {
		yPos=mY;
		shape.setPosition(mX, mY);
		shape.setSize({paddleWidth, paddleHeight});
		shape.setFillColor(Color::Red);
		shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	}

	void update(sf::Vector2i mp) {
		shape.setPosition(mp.x, yPos);
	}
};

struct Brick : public Rectangle {
	bool destroyed{false};

	Brick(float mX, float mY) {
		shape.setPosition(mX, mY);
		shape.setSize({blockWidth, blockHeight});
		shape.setFillColor(Color::Yellow);
		shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
	}
};

template <class T1, class T2>
bool isIntersecting(T1& mA, T2& mB) noexcept {
	return mA.right() >= mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall) noexcept {
	if(!isIntersecting(mPaddle, mBall)) return;
	mBall.velocity.y = -ballVelocity;
	if(mBall.x() < mPaddle.x()) mBall.velocity.x = -ballVelocity;
	else mBall.velocity.x = ballVelocity;
}

void testCollision(Brick& mBrick, Ball& mBall) noexcept {
	if(!isIntersecting(mBrick, mBall)) return;
	mBrick.destroyed = true;
	float overlapLeft{mBall.right() - mBrick.left()};
	float overlapRight{mBrick.right() - mBall.left()};
	float overlapTop{mBall.bottom() - mBrick.top()};
	float overlapBottom{mBrick.bottom() - mBall.top()};
	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
	float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
	float minOverlapY{ballFromTop ? overlapTop : overlapBottom};
	if(abs(minOverlapX) < abs(minOverlapY)) mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
	else mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

struct Game {
	RenderWindow window{{windowWidth, windowHeight}, "Arkanoid"};
	float lastFt{0.f}, currentSlice{0.f};
	bool running{false};
	Ball ball{windowWidth / 2, windowHeight / 2};
	Paddle paddle{windowWidth / 2, windowHeight - 50};
	vector<Brick> bricks;

	Game() {
		window.setFramerateLimit(240);
		window.setMouseCursorVisible(false);
		for(int iX{0}; iX < countBlocksX; ++iX) for(int iY{0}; iY < countBlocksY; ++iY) bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3));
	}

	void run() {
		running = true;
		while(running) {
			auto timePoint1(chrono::high_resolution_clock::now());
			window.clear(Color::Black);
			inputPhase();
			updatePhase();
			drawPhase();
			auto timePoint2(chrono::high_resolution_clock::now());
			auto elapsedTime(timePoint2 - timePoint1);
			float ft{chrono::duration_cast<chrono::duration<float, milli>>(elapsedTime).count()};
			lastFt = ft;
			auto ftSeconds(ft / 1000.f);
			auto fps(1.f / ftSeconds);
			window.setTitle("FT: " + to_string(ft) + "\tFPS: " + to_string(fps));
		}
	}

	void inputPhase() {
		Event event;
		while(window.pollEvent(event)) if(event.type == Event::Closed) { window.close(); break; }
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) running = false;
	}

	void updatePhase() {
		sf::Vector2i mousePos=sf::Mouse::getPosition(window);
		currentSlice += lastFt;
		for(; currentSlice >= ftSlice; currentSlice -= ftSlice) {
			ball.update(ftStep);
			paddle.update(mousePos);
			testCollision(paddle, ball);
			for(auto& brick : bricks) testCollision(brick, ball);
			bricks.erase(remove_if(begin(bricks), end(bricks),
			[](const Brick& mBrick) { return mBrick.destroyed; }),
			end(bricks));
		}
	}

	void drawPhase() {
		window.draw(ball.shape);
		window.draw(paddle.shape);
		for(auto& brick : bricks) window.draw(brick.shape);
		window.display();
	}
};

int main() {
	Game{}.run();
	return 0;
}
