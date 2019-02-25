#include "Test_Pan.h"
#include "Tree_Node.cpp"
using namespace Graph_lib; 

void set_window_assets(vector<int> int_vect, Hunter_window* game_win, Rectangle* back_ground, Text* blue_text, Text* ai_indic, Text* user_indic, Text* let_ai_move){
  game_win->attach(*back_ground);
  ai_indic->set_color(Color::magenta);
  user_indic->set_color(Color::magenta);
  ai_indic->set_font_size(15);
  user_indic->set_font_size(15);
  game_win->attach(*ai_indic);
  game_win->attach(*user_indic);
  for(int i = 0; i < int_vect.size(); ++i){
    blue_text = new Text{Point{50,12+(i*40)}, to_string(i+1).c_str()};
    blue_text->set_color(Color::magenta);
    blue_text->set_font_size(12);
    game_win->attach(*blue_text);
  }
  back_ground->set_fill_color(Color::black);
  let_ai_move->set_font_size(15);
  let_ai_move->set_color(Color::black);
}

void run_game(vector<int> int_vect, Hunter_window* game_win, In_box* in, vector<Pancake*> panc_vect, vector<Pancake*> ai_panc_vect, bool& ai_won, bool& user_won, bool& tied, Text* let_ai_move, Tree_Node tn, Tree* t, int& difficulty){
  int pos = 0;
  while(!is_game_over(cake_to_int_vect(panc_vect), cake_to_int_vect(ai_panc_vect), user_won, ai_won, tied)){
    game_win->attach(*in);
    game_win->wait_for_button();
    pos = in->get_int();
    if(pos != -999999 && pos <= panc_vect.size() && pos > 0){
      panc_vect = move_swap(pos, game_win, panc_vect, 0);
      game_win = draw_pancakes(int_vect.size(), game_win, panc_vect);
      Fl::redraw();
      sleep(1);
    }
    game_win->detach(*in);
    game_win->attach(*let_ai_move);
    tn = make_move(tn, t, difficulty, 0);
    game_win->wait_for_button();
    sleep(1);
    ai_panc_vect = move_swap(tn.index, game_win, ai_panc_vect, 1);
    game_win = draw_pancakes(int_vect.size(), game_win, ai_panc_vect);
    game_win->detach(*let_ai_move);
  }
}

void end_game(vector<int> int_vect, Hunter_window* game_win, Text* ai_indic, Text* user_indic, bool user_won, bool ai_won, bool tied, int& score, int difficulty){
  Text* game_end;
  if(user_won){
    game_end = new Text{Point{100,360}, "Game Over, YOU WON, Hit Move Button"};
    score =  2*int_vect.size() * (difficulty + 1);
  }
  else if(ai_won){
    game_end = new Text{Point{100,360}, "Game Over, YOU LOST, Hit Move Button"};
    score = int_vect.size();
  }
  else{
    game_end = new Text{Point{100,360}, "Game Over, YOU TIED, Hit Move Button"};
    score = int_vect.size() * (difficulty + 1);
  }
  game_win->detach(*ai_indic);
  game_win->detach(*user_indic);
  delete ai_indic, user_indic;
  game_end->set_color(Color::green);
  game_end->set_font_size(20);
  game_win->attach(*game_end);
  game_win->wait_for_button();
  sleep(1);
  game_win->detach(*game_end);
  delete game_end;

}

void clean_window(Hunter_window* game_win, Rectangle* back_ground, Text* blue_text, Text* let_ai_move, In_box* in, Tree* t, vector<Pancake*> panc_vect, vector<Pancake*> ai_panc_vect){
  game_win->detach(*back_ground);
  game_win->detach(*blue_text);
  delete back_ground, blue_text, let_ai_move, in, t, ai_panc_vect, panc_vect;
  game_win->hide();
  delete game_win;
}

int flip_screen(int difficulty, vector<int> int_vect){
  int score = 0;
  bool user_won = false, ai_won = false, tied = false;
  Hunter_window* game_win = new Hunter_window(Point{100,100},600,400," ");
  Rectangle* back_ground = new Rectangle(Point(0,0),600,370);
  Text* blue_text;
  Text* ai_indic = new Text{Point(350, 360), "AI STACK"};
  Text* user_indic = new Text{Point(100, 360), "USER STACK"};
  Text* let_ai_move = new Text{Point{130,395}, "Hit move to let AI move"};
  In_box* in = new In_box(Point(300, 370), 40, 30, "Flip at magenta number: ");
  vector<Pancake*> panc_vect, ai_panc_vect; 
  Tree* t = new Tree();
  Tree_Node tn;
  tn.node = int_vect;
  t->next_start_node = tn;
  pair<string,Tree_Node> tn_pair (tn.key, tn);
  t->created_map.insert(tn_pair);
  panc_vect = int_to_cake_vect(int_vect, false), ai_panc_vect = int_to_cake_vect(int_vect, true);
  set_window_assets(int_vect, game_win, back_ground, blue_text, ai_indic, user_indic, let_ai_move);
  game_win = draw_pancakes(int_vect.size(), game_win, panc_vect), game_win = draw_pancakes(int_vect.size(), game_win, ai_panc_vect);
  run_game(int_vect, game_win, in, panc_vect, ai_panc_vect, ai_won, user_won, tied, let_ai_move, tn, t, difficulty);
  end_game(int_vect, game_win, ai_indic, user_indic, user_won, ai_won, tied, score, difficulty);
  clean_window(game_win, back_ground, blue_text, let_ai_move, in, t, panc_vect, ai_panc_vect);
  Fl::run();
  return score;
}
