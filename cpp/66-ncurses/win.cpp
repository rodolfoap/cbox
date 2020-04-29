#include <ncurses.h>
#include <unistd.h>
#define LOG std::cerr<<">>> "<<__FILE__<<"["<<__LINE__<<"]:"<<__func__<<"();"<<std::endl;


int main(){
	initscr();
	WINDOW* win=newwin(10, 20, 10, 10);
	refresh();
	box(win, 0, 0);
	wrefresh(win);
	getch();
	endwin();
	return 0;
} /*

Other functions:
	raw():			Prints raw characters
	move(y/2, x/2):		mvprintw() does the same
	printw(): 		mvprintw() does the same

*/
