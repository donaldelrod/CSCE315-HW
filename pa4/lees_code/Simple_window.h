
#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h" 
#include "Graph.h"

using namespace Graph_lib;

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); 

private:
    Button next_button;     
    bool button_pushed;     

    static void cb_next(Address, Address); 
    void next();            

};

#endif 