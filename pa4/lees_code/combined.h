#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

struct High_scores : Graph_lib::Window{
	High_scores(Point xy, int w, int h, const string& title);
	void next();
	
	string level_3();
	string level_4();
	string level_5();
	string level_6();
	string level_7();
	
	int difficulty_level=0;
	int num_pancakes = 0;

	void two()   {	difficulty_level=2;	};
	void three() {	difficulty_level=3; };
	void four()  {	difficulty_level=4; };
	void five()  {	difficulty_level=5; };
	void six()   {	difficulty_level=6; };
	void seven() {	difficulty_level=7; };
	void eight() {	difficulty_level=8; };
	void nine()  {	difficulty_level=9; };


	void two_p()   {num_pancakes=2;};
	void three_p() {num_pancakes=3;};
	void four_p()  {num_pancakes=4;};
	void five_p()  {num_pancakes=5;};
	void six_p()   {num_pancakes=6;};
	void seven_p() {num_pancakes=7;};
	void eight_p() {num_pancakes=8;};
	void nine_p()  {num_pancakes=9;};


	void quit(){ hide(); };
	string init;

private:
	Text scores_title;
	Text message;
	Text message2;
	
	Text initial_3;
	Text initial_4;
	Text initial_5;
	Text initial_6;
	Text initial_7;
	
	Button quit_button;
	Button next_button;
	
	Button two_button;
	Button three_button;
	Button four_button;
	Button five_button;
	Button six_button;
	Button seven_button;
	Button eight_button;
	Button nine_button;


	Button two_button_p;
	Button three_button_p;
	Button four_button_p;
	Button five_button_p;
	Button six_button_p;
	Button seven_button_p;
	Button eight_button_p;
	Button nine_button_p;
	
	In_box initials;
	static void cb_quit(Address, Address pw) { reference_to<High_scores>(pw).quit(); }
};

void new_scores(string add_init,double add_score, int difficulty_level);