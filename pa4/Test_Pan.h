#include "Window.h"
#include "Hunter_window.h"
#include <algorithm> 
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
using namespace std;
struct Pancake{
  Text* cake_num = new Text(Point(0,0), "");
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

vector<int> cake_to_int_vect(vector<Pancake*> panc_vect){
  vector<int> int_vect; 
  for(int i = 0; i < panc_vect.size(); ++i){
    int_vect.push_back(panc_vect[i]->key_size);
  }
  return int_vect;
}



Hunter_window* draw_pancakes(int num, Hunter_window* win, vector<Pancake*> panc_vect) //draw pancakes based on a certain number of inputs, should return an altered window  
{
  for(int i = panc_vect.size()-1; i >= 0; --i){
    panc_vect[i]->cake_num = new Text{Point{panc_vect[i]->rect_x + (panc_vect[i]->rect_width/2),12+(i*40)}, panc_vect[i]->str_key.c_str()};
    panc_vect[i]->cake_num ->set_font_size(12); //sets font size to 12 
    panc_vect[i]->cake_num ->set_color(Color::cyan);
    win->attach(*(panc_vect[i]->cake_num));
    panc_vect[i]->maroon_rect = new Rectangle{Point{panc_vect[i]->rect_x,(i*40)},panc_vect[i]->rect_width,20}; // x,y, width, height
    panc_vect[i]->rect_y = (i*40);
    panc_vect[i]->maroon_rect->set_color(Color::cyan); 
    win->attach(*(panc_vect[i]->maroon_rect)); //dereference pointers before passing
  }
  return win;
}

vector<Pancake*> move_swap(int swap_pos, Hunter_window* win, vector<Pancake*> panc_vect, bool is_AI){
  std::reverse(panc_vect.begin(), panc_vect.begin() + swap_pos);
  for(int i = 0; i < panc_vect.size(); ++i){
    win->detach(*(panc_vect[i]->cake_num)); 
    win->detach(*(panc_vect[i]->maroon_rect));
    delete panc_vect[i]->cake_num;
    delete panc_vect[i]->maroon_rect; 
  }
  return panc_vect;
}

bool is_game_over(vector<int> v1, vector<int> v2, bool& b1, bool& b2, bool& b3)
{
  if(is_sorted(v2.begin(), v2.end()) && is_sorted(v1.begin(), v1.end()))
  {
    b3 = true;
    return true;
  }
  else if(is_sorted(v1.begin(), v1.end()))
  {
    b1 = true;
    return true;
  }
  else if(is_sorted(v2.begin(), v2.end()))
  {
    b2 = true;
    return true;
  }
  return false;
}
