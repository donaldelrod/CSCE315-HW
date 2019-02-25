#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <curses.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include "DisplayScores.cpp"
using namespace std;
/*
    istringstream iss("1a1b4a4b9");
    cin.rdbuf(iss.rdbuf());
    cin.clear();
    string dummy;
    cin >> dummy;
*/

void test_get_input();
void test_wait_for_input();
void test_parsed_string();
string get_input(vector<char> line);
vector<string> parse_string(string line);

int main(){
    test_parsed_string();
    test_wait_for_input();
    test_get_input();
    return 0;
}

void test_get_input(){
    cout << "Performing tests to see if gets max input of 3 and min of 2...\n";
    vector<char> zzz = {90,90,90,13};
    vector<char> zz = {90,90,13};
    vector<char> backspace = {90,90,90,90,127,13};
    vector<char> long_input = {90, 90, 90, 90,13};
    vector<vector<char>> inputs = {zzz, zz, backspace, long_input};
    for(unsigned long int i=0; i<inputs.size(); ++i){
        cout << "Test " << i << ":\t";
        string rline = get_input(inputs.at(i));
        if (rline.size() <= 3 && rline.size() >= 2){
            cout << "Passed\n";
        }
        else {
            cout << "Failed\n";
        }
    }
}

string get_input(vector<char> line){
    string input = "";
    char c;
    int i=0;
    do
    {
        c = line.at(i);
        if(((c>=65 && c<=90) || (c>=97 && c<=122)) && input.length()<3){
            c = toupper(c); //only allows alpha and up to 3 chars
            input += c;
        }
        else if((c==127 || c==8) && input.length()>0){ //backspace
            input.pop_back();
        }
        ++i;
    } while(c != 13); //exits if enter is pressed
    return input;
}

void test_wait_for_input(){
    cout << "Performing tests to see if waits on enter command...\n";
    vector<int> cmds = {64, 32, 9, 13};
    unsigned long int i = 0;
    int getcharvalue = 0;
    do{
        cout << "Test " << i << ":\t";
        getcharvalue = static_cast<char> (cmds.at(i));
        ++i;
        if(getcharvalue != 13 && i != 4){
            cout << "Passed\n";
        }
        else if (getcharvalue == 13 && i != cmds.size()){
            cout << "Failed\n";
        }
        else if(getcharvalue == 13 && i == cmds.size()){
            cout << "Passed\n";
        }
        else {
            cout << "Failed\n";
        }
    }while(getcharvalue != 13);
}

void test_parsed_string() {
    cout << "Performing tests to see if file is being parsed correctly...\n";
    vector<string> lines = {"Dan 500", "Don 200", "Hun 400", "JD 5"};
    vector<string> names = {"Dan", "Don", "Hun", "JD"};
    vector<string> scores = {"500", "200", "400", "5"};
    for(unsigned long int i=0; i<lines.size(); ++i){
        vector<string> parsed_line = parse_string(lines.at(i));
        cout << "Test " << i << ":\t";
        if(parsed_line.at(0) == names.at(i) && parsed_line.at(1) == scores.at(i)){
            cout << "Passed\n";
        }
        else{
            cout << "Failed\n";
        }
    }
}

vector<string> parse_string(string line){ //helper function to delimit whitespace
    vector<string> vs;
    string s = "";
    while(line.length() > 0){
        if(line.at(0) != ' ' && line.at(0) != '\t' && line.length() > 1) {
            s += line.at(0);
            line.erase(0,1);
        }
        else if(line.length() == 1){ //case where there is only 1 char left
            s += line.at(0);
            vs.push_back(s);
            line.erase(0,1);
            s = "";
        }
        else { //case where there is whitespace
            vs.push_back(s);
            line.erase(0,1);
            s = "";
        }
    }
    return vs;
}
