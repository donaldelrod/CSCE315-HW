#include "flip.cpp"
#include <unordered_map>
#include <string>
#include <queue> 
#include <stack> 

#ifndef Tree_Node_H
#define Tree_Node_H

struct Tree;

//structure that contains the pancake stack as the node, and all posibilities as the children
struct Tree_Node {
	vector<int> node; //the current node we are on when traversing
	int index; //the index at which this nodes parent was flipped 
	int node_sortedness = 1000; //the sortedness value of the current node based on the sortedness value, starts off withi impossible value
	int depth = 0; 
	int closeness = 0; //place in order which it was put into priority queue
	Tree_Node* parent; 
	string parent_key;
	string key = " ";
	void set_children(Tree* t); //creates the children of the current node using the sortednessfunction
	void set_sortedness(); //sets the node sortedness of all of the children
	Tree_Node(){} 
	Tree_Node(vector<int> n){
		node = n;
		for (unsigned int i = 0; i < n.size(); ++i)
			key += to_string(n[i]);
	}
};
	
struct Tree
{
	int closeness = 0; //semi-global closeness which is updated each time a new level of nodes are created as children
	std::unordered_map<std::string, Tree_Node> created_map = {}; //a map of all of the nodes we have already traversed, if we come across something already in the list we know not to use it 
	priority_queue<Tree_Node> mpq; //minimum priority queue of all of the available nodes 
	stack <Tree_Node> down_stack; //when we have a node in mind and need to bubble up using the queue then back down when we can
	queue <Tree_Node> up_queue; //bubble up the tree to find path to desired node
};

bool operator<(const Tree_Node& a, const Tree_Node& b) //flip the order of comparing nodes so that our queue may be of minimum priority
{
	if(a.node_sortedness == b.node_sortedness){ //if the sortedness is equal be sure to pick the one that was in the queue first
		return a.closeness > b.closeness;
	}
    return ((a.node_sortedness > b.node_sortedness));
}

#endif
