//Lysander Gutierrez

#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Splash_screen.h"
#include "Window.h"
#include "combined.cpp"
//#include "FL/Fl_JPEG_Image.H"

const Point tl {100,100};
const auto win_width {600};
const auto win_height {400};
const string win_title {"Jimmy Neutrons 2.0: The Panckake Flippers"};

Instructions_window::Instructions_window(Point xy, int w, int h, const string& title)
    :Window(xy, w, h, title),
	
    quit_button(Point(w-button_width,0), button_width, button_height, "Quit", cb_quit),
    next_button(Point((w/2 - button_width/2),next_from_top), button_width, button_height, "Continue", cb_next),
	
    instructions_title(Point((w/2 - title_offset), title_from_top), title_text),
	
    instructions_line1(Point((w/2 - instructions_offset), instructions_from_top), instructions_text1),
    instructions_line2(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*1), instructions_text2),
    instructions_line3(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*2), instructions_text3),
    instructions_line4(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*3), instructions_text4),
    instructions_line5(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*4), instructions_text5),
    instructions_line6(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*5), instructions_text6),
    instructions_line7(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*6), instructions_text7),
    instructions_line8(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*7), instructions_text8),
    instructions_line9(Point((w/2 - instructions_offset), instructions_from_top + instructions_height*8), instructions_text9)
{
    attach(quit_button);
    attach(next_button);

    attach(instructions_title);
    instructions_title.set_font_size(title_size);
    //Fl_JPEG_Image* gif= new Fl_JPEG_Image("image.jpg");

    attach(instructions_line1);
    attach(instructions_line2);
    attach(instructions_line3);
    attach(instructions_line4);
    attach(instructions_line5);
    attach(instructions_line6);
    attach(instructions_line7);
    attach(instructions_line8);
    attach(instructions_line9);
	
	instructions_line1.set_font_size(instructions_size);
	instructions_line2.set_font_size(instructions_size);
	instructions_line3.set_font_size(instructions_size);
	instructions_line4.set_font_size(instructions_size);
    instructions_line5.set_font_size(instructions_size);
    instructions_line6.set_font_size(instructions_size);
    instructions_line7.set_font_size(instructions_size);
    instructions_line8.set_font_size(instructions_size);
    instructions_line9.set_font_size(instructions_size);

    gui_main();
}

void Instructions_window::next()
{
    hide();
    High_scores hi(tl, win_width, win_height, win_title);
    score = hi.score;
}

Splash_window::Splash_window(Point xy, int w, int h, const string& title)
    :Window(xy, w, h, title),
	
    quit_button(Point(w-button_width,0), button_width, button_height, "Quit", cb_quit),
    next_button(Point((w/2 - button_width/2),next_from_top), button_width, button_height, "Start", cb_next),
	
    splash_title(Point(w/2 - title_offset,title_from_top), title_text),
    names(Point(w/2 - names_offset,names_from_top), names_text)
{
    attach(quit_button);
    attach(next_button);

    attach(splash_title);
    attach(names);
	
	splash_title.set_font_size(title_size);
    names.set_font_size(names_size);

    gui_main();
}

void Splash_window::next()
{
    hide();
    Instructions_window in(tl, win_width, win_height, win_title);
    score = in.score;
}

//int main() { Splash_window splash_window(tl, win_width, win_height, win_title); }
