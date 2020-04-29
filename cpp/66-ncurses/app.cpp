#include <ncurses.h>
#include <unistd.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;

void update(char c) {
	int x, y;
	getmaxyx(stdscr, y, x);
	mvprintw(y/2, x/2,"Hello, World! %d", c);
	refresh();
}

int main(){
	initscr();
//	noecho();
//	int c;
//	attron(A_BOLD);
//	attron(A_REVERSE);
//	curs_set(1);
	//start_color();
	//use_default_colors();
	//init_pair(1, COLOR_GREEN, COLOR_BLACK);
	//init_pair(2, COLOR_CYAN, COLOR_BLUE);
	//attron(COLOR_PAIR(1));

	// main loop, close with q;
//	update(0);
//	while((c=getch())!=113) update(c);

	// Bye!
	//clear();
	WINDOW* win=newwin(10, 20, 10, 10);
	refresh();
	//wbkgd(win, COLOR_PAIR(2));
	//wmove(win, getmaxy(win)/2, getmaxx(win)/2);
	box(win, 0, 0);
//	wmove(win, 5, 5);
//	wprintw(win, "Bye!");
	//refresh();
	wrefresh(win);
getch();
//	usleep(1000000);

	endwin();
	return 0;
} /*

Other functions:
	raw():			Prints raw characters
	move(y/2, x/2):		mvprintw() does the same
	printw(): 		mvprintw() does the same

*/
