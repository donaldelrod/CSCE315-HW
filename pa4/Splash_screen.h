//Lysander Gutierrez, Harrison Foster

#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

struct Instructions_window : Graph_lib::Window
{
    Instructions_window(Point xy, int w, int h, const string& title);
    int score = 0;
private:	
	int button_width {70};
    int button_height {20};
    int next_from_top {300};
	
	Button quit_button;
    Button next_button;
	
	void quit() { exit(0); }
    void next();
	static void cb_quit(Address, Address pw) { reference_to<Instructions_window>(pw).quit(); }
    static void cb_next(Address, Address pw) { reference_to<Instructions_window>(pw).next(); }
	
	string title_text {"Instructions"};
	int title_size {24};
    int title_from_top {100};
    int title_offset = title_text.length()*title_size/4.0;
	
	Text instructions_title;
	
	string instructions_text1 {"1: The objective of the game is to order a stack of unordered pancakes"         };
    string instructions_text2 {"into ascending order by flipping the stack between certain cakes"     };
    string instructions_text3 {"2: On the following screen, enter the number of pancakes you wish to sort."        };
    string instructions_text4 {"3: Next, enter your desired difficulty. "    };
    string instructions_text5 {"4: Choose the order of pancakes you wish to begin with, or choose random. "};
    string instructions_text6 {"5: Enter your initials. "};
    string instructions_text7 {"6: Use the arrow keys to select a flip position for your spatula. "};
    string instructions_text8 {"7: The order of the pancakes above the flip position will then be reversed."};
    string instructions_text9 {"8: If you order the pancakes faster than the computer, you win!"};
    
    int instructions_size {14};
    int instructions_from_top {150};
    int instructions_height {instructions_size};
    int instructions_offset {250};
		
    Text instructions_line1;
    Text instructions_line2;
    Text instructions_line3;
    Text instructions_line4;
    Text instructions_line5;
    Text instructions_line6;
    Text instructions_line7;
    Text instructions_line8;
    Text instructions_line9;
};

struct Splash_window : Graph_lib::Window
{
public:
    Splash_window(Point xy, int w, int h, const string& title);
    int score = 0;
private:
	int button_width {70};
    int button_height {20};
    int next_from_top {250};
	
	Button quit_button;
    Button next_button;
	
	void quit() { exit(0); }
    void next();
    static void cb_quit(Address, Address pw) { reference_to<Splash_window>(pw).quit(); }
    static void cb_next(Address, Address pw) { reference_to<Splash_window>(pw).next(); }

    string title_text {"PANFLIPCAKE"};
	int title_size {36};
    int title_from_top {150};
    int title_offset = title_text.length()*title_size/4.0;
	
	Text splash_title;
	
	string names_text {"Team 2: Hunter Hewitt, Donald Elrod, Austin Fry, Nandan Gade, Daniel Gunther, Lee Gutierrez"};
    int names_size {14};
    int names_from_top {325};
    int names_offset = names_text.size()*names_size/4.0;

    Text names;
};