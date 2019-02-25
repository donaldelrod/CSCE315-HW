#ifndef GET_NUM_PANCAKES_WINDOW_H
#define GET_NUM_PANCAKES_WINDOW_H

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "FL/Fl_JPEG_Image.H"
#include <iostream>     
#include <fstream>  
#include <sstream>      
#include <vector>    
#include <unistd.h>
#include <cstring>
#include <cstdlib>

using namespace Graph_lib;

struct get_initials_window: Graph_lib::Window {
    get_initials_window(Point xy, int w, int h, const string& title);
    
    void set_initials(sting i) {
        initials = i;
    }

    private:
        string initials;
        std::vector<string> scores;
        Text* prompt;
        Text* score1;
        Text* score2;
        Text* score3;
        Text* score4;
        Text* score5;
};

std:vector<string> load_scores() {
    std::vector<string> top5scores();
    ifstream ifs("scores.txt");
    if(!ifs) {
        std::cerr << "can't open file\n";
        exit(0);
    }
    //reads line by line from file and displays it
    string line;
    while(getline(ifs, line)) {
        top5scores.push_back(parse_string(line));
    }
    ifs.close();
}

get_initials_window::get_initials_window(Point xy, int w, int h, const string& title)
    :Window(xy, w, h, title) 
{
    prompt = new Text(Point(75, 100), "High Scores!");
    prompt -> set_font_size(15);

    std::vector<string> scores = load_scores();

    score1 = new Text(Point(200, 150), 100, 30, scores.at(0));
    score2 = new Text(Point(200, 180), 100, 30, scores.at(0));
    score3 = new Text(Point(200, 210), 100, 30, scores.at(0));
    score4 = new Text(Point(200, 240), 100, 30, scores.at(0));
    score5 = new Text(Point(200, 270), 100, 30, scores.at(0));

    attach(*prompt);
    attach(*score1);
    attach(*score2);
    attach(*score3);
    attach(*score4);
    attach(*score5);
}


#endif