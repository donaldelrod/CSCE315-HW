#include "Part_One.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

bool are_files_equal( string filename1, string filename2)
{
    int count = 0;
    ifstream first,test;
    first.open(filename1.c_str());
    test.open(filename2.c_str());
    string string1, string2;
    while(!first.eof()){
    getline(first, string1);
    getline(test, string2); 
    if(string1 != string2){
      ++count;
      if(count > 2)
      {
        cout << "Tests Failed";
        first.close();
        test.close();
        return false;
    }
  }
  }
  first.close();
  test.close();
  cout << "Tests Passed";
  return true;
}

void Part_One::run_Part_One(WINDOW* wind){  
      box(wind, 0, 0);
      mvwprintw(wind, 6, 22, "PANCFLIPAKE: A GAME BY DRAGONFORCE"); //start printing splash screen instructions from the board object 
      mvwprintw(wind, 7, 35, "GROUP 3");
      mvwprintw(wind, 8, 15, "JOHN DORMAN, DONALD ELROD, HUNTER HEWITT, DANIEL LE"); 
      mvwprintw(wind, 16,23, "------------------------------");
      mvwprintw(wind, 14,23, "------------------------------");
      wrefresh(wind); //refresh the window 
      wattron(wind, A_BLINK); // turn on blinking
      mvwprintw(wind, 15, 23, "|PRESS ENTER TO PLAY OUR GAME|");
      wrefresh(wind);
      usleep(3);
      wattroff(wind, A_BLINK); //turn off blinking 
  refresh();
  scr_dump("to_screen_one.txt");
  are_files_equal("to_screen_one.txt", "test_screen_one.txt");
  wclear(wind); //clear the window 
  werase(wind); //erase just in case 
  wrefresh(wind);
  scr_dump("empty_screen.txt");
  are_files_equal("empty_screen.txt", "test_empty_screen.txt");
}

void Part_One::print_instructions(WINDOW* wind) { 
    deleteln();
    box(wind, 0, 0);
    mvwprintw(wind, 6, 10, "INSTRUCTIONS: ");
    mvwprintw(wind, 7, 4, "1: The objective of the game is to order a stack of unordered pancakes ");
    mvwprintw(wind, 8, 4, "into ascending order by flipping the stack between certain cakes");
    mvwprintw(wind, 10, 4, "2: On the following screen, enter the number of pancakes you wish to sort. ");
    mvwprintw(wind, 12, 4, "3: Next, enter your desired difficulty. ");
    mvwprintw(wind, 14, 4, "4: Choose the order of pancakes you wish to begin with, or choose random. ");
    mvwprintw(wind, 16, 4, "5: Enter your initials. ");
    mvwprintw(wind, 18, 4, "6: Use the arrow keys to select a flip position for your spatula. ");
    mvwprintw(wind, 20, 4, "7: The order of the pancakes above the flip position will then be reversed.");
    mvwprintw(wind, 22, 4, "8: If you order the pancakes faster than the computer you win!");
    mvwprintw(wind, 24, 4, "Press enter to continue ");
    wrefresh(wind);
    usleep(3);
  
  refresh();
  scr_dump("to_screen_two.txt");
  are_files_equal("to_screen_two.txt", "test_screen_two.txt");
  wrefresh(wind);
  clear();
  wrefresh(wind);
  scr_dump("empty_screen.txt");
  are_files_equal("empty_screen.txt", "test_empty_screen.txt");
}
