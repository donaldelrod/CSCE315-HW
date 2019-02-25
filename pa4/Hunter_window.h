
#ifndef Hunter_WINDOW_GUARD
#define Hunter_WINDOW_GUARD 1

#include "GUI.h" 
#include "Graph.h"
#include <unistd.h>

using namespace Graph_lib;

struct Hunter_window : Graph_lib::Window {
    Hunter_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); 

private:
    Button next_button;     
    bool button_pushed;     

    static void cb_next(Address, Address); 
    void next();            

};

#endif 