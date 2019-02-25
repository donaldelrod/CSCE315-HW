#include "Tree_Node.cpp"
#include <algorithm>
//this file will be the header for the AI tests

class Test_AI
{
	bool you_tests_passed = false;
public: 
	vector<bool> function_passes;
	vector<bool> valid_moves;
	vector<bool> sols_found;
	vector<bool> lt_150_vect;
	vector<int> rand_stack_2 = {2,1};
	vector<int> rand_stack_3 = {3,1,2};
	vector<int> rand_stack_4 = {4,1,3,2};
	vector<int> rand_stack_5 = {5,1,3,4,2};
	vector<int> rand_stack_6 = {6,1,4,2,3,5};
	vector<int> rand_stack_7 = {3,4,1,6,7,5,2};
	vector<int> rand_stack_8 = {8,1,3,2,7,4,5,6};
	vector<int> rand_stack_9 = {9,1,8,4,6,2,3,5,7};
	int difficulty;
	bool get_passed() {return you_tests_passed;}
	void set_passed(bool b) {you_tests_passed = b;}
	void is_valid_move(Tree_Node prev, Tree_Node next); //should check that the move is valid and push into vector bools
	bool all_valid_moves();
	void is_valid_solution(Tree_Node tn); //should check that the solution given was valid
	bool all_solutions_found();
	void lt_150_moves(int i); 
	bool all_lt_150(); //checks that all solutions took less than 150 solutions to find
	bool all_tests_passed(); 
	void run_test(vector<int> node, int diff);
};