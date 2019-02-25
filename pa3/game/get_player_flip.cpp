#include <vector>
#include <curses.h>
#include <unistd.h>
#include "find_solution.h"

using namespace std;

//Moves the spatula cursor as dicated by the user input from get_player_flip, moves y units and x units to location and refreshes window.
void move_spatula(WINDOW* spatula, int y, int x) {
        mvwin(spatula, y, x);
        mvwprintw(spatula, 0, 0, "<----");
        wrefresh(spatula);
}

/** 
 * Prints the best move for the user to make when the user presses H when playing
 */
void print_hint(WINDOW* win, vector<int> player) {
	const vector<int> cplayer = player;
	vector<int>* sol = find_solution(cplayer);
	if (sol != nullptr) {
		mvwprintw(win, 3, 2, string("Hint: flip pancake " + to_string( sol->at(0) )).c_str());
		wrefresh(win);
		delete sol;
		sleep(2);
		mvwprintw(win, 3, 2, string("                     ").c_str());
		wrefresh(win);
	}
}


/* Enables the user to choose a flip by moving a small arrow cursor around the stack with WS keys, designating 
 * what portion of the stack should be flipped. Returns an integer value later processed by another
 * function for flipping that will flip the stack the way the user desires. Cursors "moves" by
 * deleting the arrow inside of it and then moving the "spatula" window only to print the same
 * arrow inside it. Bounds are checked if the flip surpasses the stack going to far above or below it.
 * User enters to confirm the flip action.*/
int get_player_flip(WINDOW* w, int stack_size, vector<int> player) {
	int x = 38, y = 13, flip = 1, c;

	WINDOW* spatula = subwin(w, 1, 5, y, x);
	mvwprintw(spatula, 0, 0, "<----");
	wmove(spatula, 0, 0);
	wrefresh(spatula);
			
	do{
		c = getchar();
		wmove(spatula, 0, 0);

		if(flip != 1 && (c == KEY_UP || c == 119)){
			for(int i = 0; i < 5; ++i) wdelch(spatula);
			y -= 3;
			flip--;
		}
		else if(flip != stack_size && (c == KEY_DOWN || c == 115)){
			for(int i = 0; i < 5; ++i) wdelch(spatula);
			y += 3;
			flip++;
		}
		else if (flip != stack_size && (c == 72 || c == 104))
			print_hint(w, player);
		
		wrefresh(spatula);	
		move_spatula(spatula, y, x);
		
	} while(c != 13);
	return flip;	
}

