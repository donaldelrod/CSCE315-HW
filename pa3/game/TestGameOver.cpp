#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <curses.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
using namespace std;

vector<string> p1 = {"DAN", "600"};
vector<string> p2 = {"HUN", "500"};
vector<string> p3 = {"DON", "300"};
vector<string> p4 = {"JD", "200"};
vector<string> p5 = {"BRD", "100"};
string initials = "ZZZ";
int player_score = 350;

void test_sort_scores();
void test_sort_scores2();
void test_sort_scores3();
vector<vector<string>> sort_scores(vector<vector<string>> top5scores, string initials, int player_score);

int main(){
    cout << "Testing to see if size of sorted scores is correct...\n";
    test_sort_scores();
    cout << "Testing to see if new score was inserted correctly...\n";
    test_sort_scores2();
    cout << "Testing to see if initials was inserted correctly...\n";
    test_sort_scores3();
    return 0;
}

void test_sort_scores3(){
    vector<vector<string>> top5scores = {p1, p2, p3, p4, p5};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(2).at(0) == "ZZZ"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(0).at(0) == "ZZZ"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {p1,p2,p3};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(2).at(0) == "ZZZ"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
}

void test_sort_scores2(){
    vector<vector<string>> top5scores = {p1, p2, p3, p4, p5};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(2).at(1) == "350"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(0).at(1) == "350"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {p1,p2,p3};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.at(2).at(1) == "350"){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
}

void test_sort_scores(){
    vector<vector<string>> top5scores = {p1, p2, p3, p4, p5};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.size() == 5){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.size() == 1){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
    top5scores = {p1,p2,p3};
    top5scores = sort_scores(top5scores, initials, player_score);
    if(top5scores.size() == 4){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
    }
}

vector<vector<string>> sort_scores(vector<vector<string>> top5scores, string initials, int player_score){
    vector<string> player;
    player.push_back(initials);
    player.push_back(to_string(player_score));
    bool found = false;
    for(unsigned long int i=0; i<top5scores.size(); ++i){
        if (stoi(top5scores.at(i).at(1)) < player_score){
            found = true;
            top5scores.insert(top5scores.begin()+i, player);
            break;
        }
    }
    if(top5scores.size() > 5){ //case where inserted and more than 5 scores
        top5scores.pop_back();
    }
    else if(top5scores.size() == 0){ //case where there were no scores
        top5scores.push_back(player);
    }
    else if(top5scores.size() < 5 && !found){ //case where there are empty slots
        top5scores.push_back(player);
    }
    return top5scores;
}