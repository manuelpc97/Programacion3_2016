#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
	int row, column;
	char word[6];

	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	getmaxyx(stdscr, row, column);
	attron(COLOR_PAIR(1));
	getstr(word);
	clear();
	mvprintw(row/2, (column-15)/2, word);
	getch();
	attroff(COLOR_PAIR(1));
	endwin();
	return 0;
}
