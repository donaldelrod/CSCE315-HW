#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <vector>
#include <iostream>
#include <string>

using namespace Graph_lib; 

struct Pancake{
	Text* cake_num;
	Rectangle* maroon_rect;
	int key_size = 0;
	int rect_width = 0;
	int rect_height = 20;
	int rect_x = 100;
	int rect_y = 380;
	bool is_AI = false;  
	string str_key = " ";
	Pancake(int key, bool _is_AI){
		key_size = key;
		is_AI = _is_AI; 
		str_key = to_string(key_size);
		rect_width = key_size*20;
		if(is_AI)
			rect_x = 350;
		else
			rect_x = 100;
	}
};


vector<Pancake*> int_to_cake_vect(vector<int> int_vect, bool is_AI){
	vector<Pancake*> panc_vect; 
	for(int i = 0; i < int_vect.size(); ++i){
		Pancake* p = new Pancake(int_vect[i], is_AI);
		panc_vect.push_back(p);
	}
	return panc_vect;
}


Graph_lib::Window* draw_pancakes(int num, Graph_lib::Window* win, vector<Pancake*> panc_vect) //draw pancakes based on a certain number of inputs, should return an altered window  
{
	string string_num; 
	for(int i = 0; i < panc_vect.size(); ++i){
		string_num = to_string((num-i));
		panc_vect[i]->cake_num = new Text{Point{panc_vect[i]->rect_x + (panc_vect[i]->rect_width/2),395 - (i*40)}, panc_vect[i]->str_key.c_str()};
		panc_vect[i]->cake_num ->set_font_size(12); //sets font size to 12 and color to white 
		panc_vect[i]->cake_num ->set_color(64);
		win->attach(*(panc_vect[i]->cake_num));
		panc_vect[i]->maroon_rect = new Rectangle{Point{panc_vect[i]->rect_x,380 - (i*40)},panc_vect[i]->rect_width,20}; // x,y, width, height
		panc_vect[i]->rect_y = 380 - (i*40);
		panc_vect[i]->maroon_rect->set_color(64); //maroon
		win->attach(*(panc_vect[i]->maroon_rect)); //dereference pointers before passing
	}
	return win;
}

Graph_lib::Window* move_swap_redraw(int swap_pos, Graph_lib::Window* win, vector<Pancake*> panc_vect, bool is_AI){
	std::reverse(panc_vect.begin(), panc_vect.begin() + swap_pos);
	for(int i = 0; i < panc_vect.size(); ++i){
		win->detach(*(panc_vect[i]->cake_num));	
		win->detach(*(panc_vect[i]->maroon_rect));
		delete panc_vect[i]->cake_num;
		delete panc_vect[i]->maroon_rect;	
	}
	win = draw_pancakes(panc_vect.size(), win, panc_vect);
	return win;
}