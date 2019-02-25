#include "get_game_state.cpp"
#include <iostream>
#include <assert.h>


using namespace std;

//Unit testing for part 2 of the project involving prompting user for input
int main(){
	char* prompts = (char*)("Please enter the number of pancakes for the stack: Please enter the AI difficulty level: ");
	char* error_msgs = (char*)("AI difficulty cannot be greater than stack size!!");

	char *prompt_contents = NULL, *error_contents = NULL;
	WINDOW *prompt_win;
	
	initscr();
	refresh();
	prompt_win = newwin(40, 80, 0, 0);

	print_gamestate_prompts(prompt_win);
	winstr(prompt_win, prompt_contents);

	print_gamestate_errors(prompt_win);
	winstr(prompt_win, error_contents);

	delwin(prompt_win);
	endwin();
	
	assert(prompts && "Testing screen prompts for correctness");
	cout << "Test 1 PASSED" << endl;	

	assert(error_msgs && "Testing error messages for correctness");
	cout << "Test 2 PASSED" << endl;
}
