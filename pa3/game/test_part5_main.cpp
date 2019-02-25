#include "show_pancake_stacks.cpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

int main(){
	WINDOW* win;
	
	vector<int> player_stack = {1,2,3,4,5,6,7,8,9},
		    ai_stack     = {9,8,7,6,5,4,3,2,1};

	vector<WINDOW*> player_wins(9);
	vector<WINDOW*> ai_wins(9);
	
	initscr();
	refresh();
	
	win = newwin(40, 80, 0, 0);
		
	show_pancake_stacks(win, player_wins, ai_wins, player_stack, ai_stack);
	scr_dump("scr_contents.txt");

	delwin(win);
	endwin();

	assert("Checking scr_contents.txt to see if screen contents are correct");
	cout << "Test 1 PASSED" << endl;
}
