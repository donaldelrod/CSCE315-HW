#include <curses.h>
#include "Part_One_Tests.cpp"

int main()
{
	vector<bool> bool_vect;
    initscr();
    refresh();
    noecho();
    clear();
    refresh();
	WINDOW* win = newwin(40, 80, 0, 0);   
    Part_One p;
   	box(win, 0, 0);  
    wrefresh(win);
    wrefresh(win);
    p.run_Part_One(win);
    box(win, 0, 0);  
    wrefresh(win);
    wrefresh(win);
    p.print_instructions(win);
    delwin(win);
    endwin();
} 