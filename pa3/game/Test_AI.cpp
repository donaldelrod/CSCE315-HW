#include "Test_AI.h"

void Test_AI::is_valid_move(Tree_Node prev, Tree_Node next){
	Tree_Node dummy;
	vector<int> swap = next.node;
	std::reverse(swap.begin(), swap.end());
	if(prev.node == swap || prev.node == next.node){
		valid_moves.push_back(true);
		return;
	}
	for(unsigned int i = 0; i < prev.node.size(); ++i){
		dummy = flip(prev.node, i);
		if(dummy.key == next.key)
			valid_moves.push_back(true);
	}
	cout << "THIS MOVE IS INVALID COME ON AI WHAT ARE YOU DOING WE'VE TALKED ABOUT THIS" << endl;
	valid_moves.push_back(false);
}

bool Test_AI::all_valid_moves(){
	for(unsigned int i = 0; i < valid_moves.size(); ++i)
		if(!valid_moves[i]){
			cout << "THERE WAS AN INVALID MOVE AT INDEX " << i << endl;
			function_passes.push_back(false);
			return false;
		}
	function_passes.push_back(true);
	return true;
}

void Test_AI::is_valid_solution(Tree_Node tn)
{
	if(is_sorted(tn.node.begin(), tn.node.end()))
		sols_found.push_back(true);
	else
	{
		cout << "THERE WAS AN INVALID SOLUTION FOUND WHY ARE YOU SO BAD AT THIS AI " << endl;
		sols_found.push_back(false);
	}
}

bool Test_AI::all_solutions_found()
{
	for(unsigned int i = 0; i < sols_found.size(); ++i)
		if(!sols_found[i]){
			cout << "THERE WAS AN INVALID SOLUTION AT INDEX " << i << endl;
			function_passes.push_back(false);
			return false;
		}
	function_passes.push_back(true);
	return true;	
}

void Test_AI::lt_150_moves(int i) //returns true if the number of moves taken was less than 150
{
	if(i < 150)
		lt_150_vect.push_back(true);
	else
	{
		cout << "WOW THAT TOOK YOU WAY TOO LONG BRO " << endl;
		lt_150_vect.push_back(false);
	}
}

bool Test_AI::all_lt_150()
{
	for(unsigned int i = 0; i < lt_150_vect.size(); ++i)
		if(!lt_150_vect[i]){
			cout << "THERE WAS A SOLUTION THAT TOOK TOO LONG AT " << i << endl;
			function_passes.push_back(false);
			return false;
		}
	function_passes.push_back(true);
	return true;	
}

bool Test_AI::all_tests_passed()
{
	for(unsigned int i = 0; i < function_passes.size(); ++i)
		if(!function_passes[i]){
			cout << "THERE WAS A TEST THAT DIDN'T PASS" << endl;
			return false;
		}
	set_passed(true);
	return true;	
}

void Test_AI::run_test(vector<int> node, int diff)
{
	int count = 0;
	Tree* t = new Tree();
	Tree_Node tn(node);
	Tree_Node prev_node;
    std::pair<std::string,Tree_Node> tn_pair (tn.key, tn);
    t->created_map.insert(tn_pair);
    for(int i = 0; i < 1000; ++i){
    	++count;
    	prev_node = tn;
    	tn = make_move(tn,t,diff);
    	if(tn.node_sortedness == 0)
    		break;
    }
    is_valid_solution(tn);
    lt_150_moves(count);
    delete t;
}