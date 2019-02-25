#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "difficulty_window.h"
#include "get_num_pancakes_window.h"

difficulty_window* diff_win;
get_num_pancakes_window* num_pancakes_win;

void num_pancakes_callback();

int main() {
  try {
    if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ", H112);
    
    
    initials_win = new get_initials_window{Point(100,100), 600, 400, "JIMMY NEUTRONS"};
    //num_pancakes_win = new get_num_pancakes_window{Point(100,100), 600, 400, "JIMMY NEUTRONS"};
    

    Button* difficulty_button;
    next_button = new Button{Point(450, 300), 100, 25, "Next", Callback(num_pancakes_callback)};
    
    initials_win -> show();
    //diff_win -> hide();
    initials_win -> attach(*next_button);
  }
  catch(exception& e) {
	  cerr << "exception: " << e.what() << '\n';
	  return 1;
  }
  catch (...) {
	  cerr << "Some exception\n";
	  return 2;
  }

  return gui_main();
}

void initials_callback() {
  //num_pancakes_win -> hide();
  //diff_win -> show();
  std::cout << "got intials" << std::endl;
}
