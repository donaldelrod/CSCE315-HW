#include "Board.h"

void clear_stuff_since_main_can_only_be_24_lines(Board* b) {
    werase(b->win);
    clear();
    b->print_box();
}

int main() {
    bool continue_playing = true;
    do{
        Board* b = new Board();
        //part 1
        clear_stuff_since_main_can_only_be_24_lines(b);
        b->display_sscreen();

        //part 2
        clear_stuff_since_main_can_only_be_24_lines(b);
        b->display_gamestate_init();

        //part 3
        clear_stuff_since_main_can_only_be_24_lines(b);
        b->display_pancake_init();

        //part 4
        clear_stuff_since_main_can_only_be_24_lines(b);
        b->display_top5_scores();

        b->generate_Tree();
        
        werase(b->win);
        clear();
        b->print_box();

    
        while(!(b->is_gameover())){
            b->already_sorted = false;
            b->display_pancake_stacks();
            b->get_player_move();
            b->get_AI_move();
            if(b->is_gameover()) {sleep(3);}
            wrefresh(b->win);
            werase(b->win);
            clear();
            b->print_box();
            ++b->num_moves;
        }
	
        //part8
        clear_stuff_since_main_can_only_be_24_lines(b);

        b->display_gameover_screen();
        if(!b->already_sorted)
            b->clear_pancake_stacks();
        continue_playing = b->play;
        delwin(b->win);
        endwin();
        delete b->t;
        delete b;
    } while(continue_playing);

    return 0;
}
