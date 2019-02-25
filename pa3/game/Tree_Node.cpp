#include "Tree_Node.h"

//this function checks whether the move from the node t, to the node s is a legal move
bool isValid(Tree_Node t, Tree_Node s){
    unsigned int count = 0;
    vector<int> dummy;
    for(unsigned int i = 0; i <= s.node.size(); ++i){
        dummy = flip(t.node, i);
        for(unsigned int j = 0; j < dummy.size(); ++j)
            if(dummy[j] == s.node.at(j))
                ++count;
        if(count == dummy.size())
            return true;
        count = 0;
    }  
    return false;
}

//this function creates the children of a node
void Tree_Node::set_children(Tree* t){
	for(unsigned int i = 1; i < node.size(); ++i){
		Tree_Node dummy((flip(node,i+1)));
		dummy.index = i+1;
		std::unordered_map<std::string,Tree_Node>::const_iterator got = t->created_map.find(dummy.key);
		if(got == t->created_map.end()){ //if the dummy node has not already been created then we will add it to our created list and priority queue 
			dummy.parent = this;
			dummy.parent_key = this->key;
			dummy.depth = this->depth;
			dummy.depth += 1;
			dummy.set_sortedness(); 
			dummy.closeness = t->closeness; //closeness allows us to keep track of which nodes were put in the priority queue first
			t->mpq.push(dummy);
			std::pair<std::string,Tree_Node> dummy_pair (dummy.key,dummy);
			t->created_map.insert(dummy_pair);
			if(dummy.node_sortedness == 0) //we don't need to keep adding children if we've already found the solution!
				return;
		}
	}
	++(t->closeness); //increase closeness every time to keep track of which nodes entered the priority queue first 
	return;
}

void Tree_Node::set_sortedness(){
	vector<bool> is_less_vect; //vector containing all of the is less bools in order
	is_less_vect.push_back(true); //the first value will always be less than the next because we begin our comparisons with zero
	node_sortedness = 0;
	for(unsigned int i = 0; i < node.size()-1; ++i){
		if(node.at(i) < node.at(i+1))
			is_less_vect.push_back(true);
		else
			is_less_vect.push_back(false);
	}
	for(unsigned int i = 0; i < is_less_vect.size() -1; ++i){
		if(is_less_vect[i] != is_less_vect[i+1]) //every time there is a switch in signs from < to > or vice versa is an increase in sortedness value
			++node_sortedness;
	}
}

Tree_Node bubble_up(Tree_Node& tn, Tree_Node& dummy, Tree_Node& dummy2, Tree* t, int diff)
{
	diff = diff + 1;
	diff = diff - 1;
	while(tn.depth > dummy2.depth+1) //while the selected move is not on the depth of the current move, move up
		tn = t->created_map.at(tn.parent_key);
	if(!isValid(dummy, tn)){ //if this move is not valid, we must go back up the tree until we find a path to this node
		t->down_stack.push(tn); //push the move that is on the level of the move we need to make so we can move down to this one
		tn = t->created_map.at(tn.parent_key); //push the move of the level that we're on, this way both tn and dummy should have ...
		t->down_stack.push(tn); //... a node on the same level
		if(tn.key == dummy.key){
			tn = t->down_stack.top();
			t->down_stack.pop();
			return tn;
		}
		while(dummy.depth != 0 && tn.depth != 0){ //while the node depths are greater than zero, go back up the tree
			tn = t->created_map.at(tn.parent_key);
			dummy = t->created_map.at(dummy.parent_key); 
			t->up_queue.push(dummy); //push dummy parent in queue so that we can make moves back up the tree
			if(tn.key == dummy.key) //if the two nodes are equal then have found a common node to go back down the tree
				break;
			t->down_stack.push(tn);
		}
		t->up_queue.pop();
		return t->created_map.at(dummy2.parent_key); //the parent of the node we were on at the beginning is where we want to start moving up
	}
	return tn;
}

Tree_Node make_move(Tree_Node& tn, Tree* t, int diff){
	Tree_Node pop_node;
	if(t->up_queue.size() > 0){
		pop_node = t->up_queue.front();
		t->up_queue.pop(); //if we need to go back up the tree, pop the queue so we can move up, keep popping until we don't need to move up anymore
		return pop_node; 
	}
	else if(t->down_stack.size() > 0){
		pop_node = t->down_stack.top(); //if we need to go down to a certain node, keep popping until we've reached that node
		t->down_stack.pop();
		return pop_node;
	}
	Tree_Node dummy = tn; 
	Tree_Node dummy2 = dummy;
	if(tn.node_sortedness != 0)
		while(tn.depth < diff+dummy2.depth){ //we may only look ahead diff amount from our current depth 
			tn.set_children(t); 
			tn = (t->mpq.top()); //tn is now the best move according to minimum priority queue 
			if(tn.node_sortedness == 0)
				break; //if the sortedness is 0 we are done, bubble up will handle bringing it back up the tree
			t->mpq.pop(); //pop only if node sortedness is not 0
		}
	tn = bubble_up(tn, dummy, dummy2, t, diff); //make the move our AI found valid
	return tn;
}
