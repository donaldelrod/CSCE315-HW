#include "Test_Pan.h"
using namespace Graph_lib; 

int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ", H112);

 /* Simple_window win1(Point(100,200),600,400,"two lines");
  Line horizontal(Point(100,100),Point(200,100));  // make a horizontal line
  Line vertical(Point(150,50),Point(150,150));     // make a vertical line
  vertical.set_style(Line_style(Line_style::solid, 1));
  win1.attach(horizontal);
  win1.attach(vertical);
  vertical.set_color(Color::magenta);
  horizontal.set_color(Color::magenta);
  win1.wait_for_button();
  return 0;*/
  Graph_lib::Window* game_win = new Graph_lib::Window(Point{100,100},600,400," ");
  In_box in(Point(300, 360), 50, 40, "Flip at red number: ");
  vector<Pancake*> panc_vect, ai_panc_vect; 
  vector<int> int_vect = {9,8,7,6,5,4,3,2,1};
  panc_vect = int_to_cake_vect(int_vect, false);
  ai_panc_vect = int_to_cake_vect(int_vect, true);
  game_win = draw_pancakes(int_vect.size(), game_win, panc_vect);
  game_win = draw_pancakes(int_vect.size(), game_win, ai_panc_vect);
  int pos;
    game_win->attach(in);
    pos = in.get_int();
    if(pos != -999999 && pos > panc_vect.size() && pos > 0)
    {
      panc_vect = move_swap(pos, game_win, panc_vect, 0);
      game_win = draw_pancakes(int_vect.size(), game_win, panc_vect);
      gui_main();
      Fl::redraw();
  }
 /* panc_vect = move_swap(9, game_win, panc_vect, 0);
  game_win = draw_pancakes(int_vect.size(), game_win, panc_vect);
  panc_vect = move_swap(9, game_win, panc_vect, 0);
  game_win = draw_pancakes(int_vect.size(), game_win, panc_vect);
  ai_panc_vect = move_swap(6, game_win, ai_panc_vect, 0);
  game_win = draw_pancakes(int_vect.size(), game_win, ai_panc_vect);*/
  Fl::run();
  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
