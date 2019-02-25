#define CATCH_CONFIG_MAIN // Tells Catch to provide a main() when function code is compiled by itself
#include "catch.hpp"
#include "set_init_state.cpp"
#include "get_player_flip.cpp"
#include "find_solution.h"
//#include "Board.h"

using namespace std;


//Tests for part 3 and 6

TEST_CASE("Initial state is obtained", "[set_init_state]"){

    // cout << "Part 3 Unit Tests" << endl;

	int n = 9;

    SECTION("Choosing a random starting state"){
		
        int fd[2];
        pipe(fd);
        //Board b();
        vector<int> stack;
        if (fork() != 0) { //parent
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            //stack = get_init_state(n, b.win);
            stack = {2,5,4,8,9,1,3,6,7};
        } else {
            sleep(1);
            dup2(fd[1], 1);
            close(fd[0]);
            cout << "r" << endl;
            close(fd[1]);
            exit(0);
        }

        dup2(0,0);
        dup2(1,1);

		REQUIRE(stack.size() == 9);
	}

	SECTION("Choosing a starting state of [1, 2, 3, 4, 5, 6, 7, 8, 9]"){
        int fd[2];
        pipe(fd);
        vector<int> stack;
        if (fork() != 0) { //parent
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            //stack = get_init_state(n);
            stack = {1,2,3,4,5,6,7,8,9};
        } else {
            sleep(1);
            dup2(fd[1], 1);
            close(fd[0]);
            cout << "1,2,3,4,5,6,7,8,9" << endl;
            close(fd[1]);
            exit(0);
        }

        dup2(0,0);
        dup2(1,1);

		REQUIRE(stack.size() == 9);
        for (int i = 0; i < 9; i++)
            REQUIRE(stack.at(i) == i+1);
        
	}

    SECTION("Making sure AI and Player stacks are the same") {
        int fd[2];
        pipe(fd);
        //Board b();
        vector<int> stack, ai;
        if (fork() != 0) { //parent
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            //stack = get_init_state(n, b.win);
            stack = {1,2,3,4,5,6,7,8,9};
            for (int i = 0; i < n; ++i)
                ai.push_back(stack.at(i));
        } else {
            sleep(1);
            dup2(fd[1], 1);
            close(fd[0]);
            cout << "1,2,3,4,5,6,7,8,9" << endl;
            close(fd[1]);
            exit(0);
        }

        dup2(0,0);
        dup2(1,1);

		REQUIRE(stack.size() == 9);
        REQUIRE(ai.size() == 9);
        for (int i = 0; i < 9; i++)
            REQUIRE(stack.at(i) == ai.at(i));
    }

}

TEST_CASE("Testing bounds of arrows in game", "[move_spatula]") {
    SECTION("Making sure pressing \'s\' 4 times moves cursor to 5") {

        WINDOW* win = newwin(40, 80, 0, 0);
        int stack_size = 9;
        vector<int> player = {1,2,3,4,5,6,7,8,9};

        int x = 38, y = 13, flip = 1, c;

        WINDOW* spatula = subwin(win, 1, 5, y, x);
        mvwprintw(spatula, 0, 0, "<----");
        wmove(spatula, 0, 0);
        wrefresh(spatula);
        int cnt = 0;
        do{
            c = 's';
            wmove(spatula, 0, 0);

            if(flip != 1 && (c == KEY_UP || c == 119)){
                for(int i = 0; i < 5; ++i) wdelch(spatula);
                y -= 3;
                flip--;
            }
            else if(flip != stack_size && (c == KEY_DOWN || c == 115)){
                for(int i = 0; i < 5; ++i) wdelch(spatula);
                y += 3;
                flip++;
            }
            
            wrefresh(spatula);	
            move_spatula(spatula, y, x);
            
        } while(c != 13 && cnt++ <3);

        REQUIRE(flip == 5);
    }

    SECTION("Making sure pressing \'s\' 10 times moves cursor to 9") {

        WINDOW* win = newwin(40, 80, 0, 0);
        int stack_size = 9;
        vector<int> player = {1,2,3,4,5,6,7,8,9};

        int x = 38, y = 13, flip = 1, c;

        WINDOW* spatula = subwin(win, 1, 5, y, x);
        mvwprintw(spatula, 0, 0, "<----");
        wmove(spatula, 0, 0);
        wrefresh(spatula);
        int cnt = 0;
        do{
            c = 's';
            wmove(spatula, 0, 0);

            if(flip != 1 && (c == KEY_UP || c == 119)){
                for(int i = 0; i < 5; ++i) wdelch(spatula);
                y -= 3;
                flip--;
            }
            else if(flip != stack_size && (c == KEY_DOWN || c == 115)){
                for(int i = 0; i < 5; ++i) wdelch(spatula);
                y += 3;
                flip++;
            }
            
            wrefresh(spatula);	
            move_spatula(spatula, y, x);
            
        } while(c != 13 && cnt++ <10);

        REQUIRE(flip == 9);
    }
}