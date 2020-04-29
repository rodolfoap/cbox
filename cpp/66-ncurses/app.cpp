#include <ncurses.h>
#include <unistd.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

void update(char c) {
	int x, y;
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/2,"Hello, World! %d", c); // moves and print
	refresh();
}

int main(){
	initscr(); // mandatory
	noecho(); // avoid echo
	int c;
	attron(A_BOLD);
	attron(A_REVERSE);
	curs_set(1); // shows (1) or hides (0) the cursor
//	start_color(); // starts the modules color
	use_default_colors(); // ncurses has horrible colors, this uses the users' default... more or less.
	init_pair(1, COLOR_GREEN, COLOR_BLACK); // id, foreground, background
	attron(COLOR_PAIR(1));

	// main loop, close with q;
	update(0); // see the function above
	while((c=getch())!=113) update(c); // exit with 'q'

	// Bye!
	clear();
	WINDOW* win=newwin(5, 20, 0, 0);
	refresh(); // required, to show the window
	box(win, 0, 0); // draws a box
	wmove(win, 2, 7); // moves relative to the window
	wprintw(win, "Bye!"); // prints on the window
	wrefresh(win); // updates window
	getch();

	for(int i=1; i<40; i++) {
		clear(); // clears memory
		refresh(); // updates screen
		mvwin(win, i, i*2); // moves window
		wrefresh(win); // updates window
		usleep(30000); // 30ms
	}

	endwin();
	return 0;
} /*

Other functions:
	raw():			Prints raw characters
	move(y/2, x/2):		mvprintw() does the same
	printw(): 		mvprintw() does the same

*/
