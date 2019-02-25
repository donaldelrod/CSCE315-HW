#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "combined.h"
#include <vector>

using namespace Graph_lib;

High_scores::High_scores(Point xy, int w, int h, const string& title)
	: Window{xy,w,h,title},
	
	scores_title{Point {20,250}, "HIGH SCORES"},
	message{Point{50, 50},"Choose a difficulty level"},
	message2(Point(50, 130), "Chose the number of pancakes to use in the game"),
	
	initial_3{Point{20, 300}, level_3()},
	initial_4{Point{20, 320}, level_4()},
	initial_5{Point{20, 340}, level_5()},
	initial_6{Point{20, 360}, level_6()},
	initial_7{Point{20, 380}, level_7()},
	
	quit_button(Point(w-70,0), 70, 20, "Quit", cb_quit),
	next_button{Point{(w/2-35), 200}, 70, 20, "Continue", [](Address, Address pw){reference_to<High_scores>(pw).next();}},
	
	two_button{Point((w/2-300), 55), 		75, 50, "2",[](Address, Address pw){reference_to<High_scores>(pw).two(); }},
	three_button{Point((w/2-225), 55), 		75, 50, "3",[](Address, Address pw){reference_to<High_scores>(pw).three(); }},
	four_button{Point((w/2-150), 55), 		75, 50, "4",[](Address, Address pw){reference_to<High_scores>(pw).four(); }},
	five_button{Point((w/2-75), 55), 		75, 50, "5",[](Address, Address pw){reference_to<High_scores>(pw).five(); }},
	six_button{Point((w/2), 55), 			75, 50, "6",[](Address, Address pw){reference_to<High_scores>(pw).six(); }},
	seven_button{Point((w/2+75), 55), 		75, 50, "7",[](Address, Address pw){reference_to<High_scores>(pw).seven(); }},
	eight_button{Point((w/2+150), 55), 		75, 50, "8",[](Address, Address pw){reference_to<High_scores>(pw).eight(); }},
	nine_button{Point((w/2+225), 55), 		75, 50, "9",[](Address, Address pw){reference_to<High_scores>(pw).nine(); }},


	two_button_p{	Point((w/2-300), 135), 	75, 50, "2",[](Address, Address pw){reference_to<High_scores>(pw).two_p(); }},
	three_button_p{	Point((w/2-225), 135), 	75, 50, "3",[](Address, Address pw){reference_to<High_scores>(pw).three_p(); }},
	four_button_p{	Point((w/2-150), 135), 	75, 50, "4",[](Address, Address pw){reference_to<High_scores>(pw).four_p(); }},
	five_button_p{	Point((w/2-75), 135), 	75, 50, "5",[](Address, Address pw){reference_to<High_scores>(pw).five_p(); }},
	six_button_p{	Point((w/2), 135), 		75, 50, "6",[](Address, Address pw){reference_to<High_scores>(pw).six_p(); }},
	seven_button_p{	Point((w/2+75), 135), 	75, 50, "7",[](Address, Address pw){reference_to<High_scores>(pw).seven_p(); }},
	eight_button_p{	Point((w/2+150), 135), 	75, 50, "8",[](Address, Address pw){reference_to<High_scores>(pw).eight_p(); }},
	nine_button_p{	Point((w/2+225), 135), 	75, 50, "9",[](Address, Address pw){reference_to<High_scores>(pw).nine_p(); }},
	
	init(""),
	initials(Point(x_max()-310,20) , 50,20, "Enter your Initials:"),
	order(Point(500, 350), 50, 20, "Enter order (leave blank for random stack order):")
{
	attach(next_button);
	attach(scores_title);
	attach(initial_3);
	attach(initial_4);
	attach(initial_5);
	attach(initial_6);
	attach(initial_7);
	attach(initials);
	attach(order);
	attach(quit_button);

	attach(two_button);
	attach(three_button);
	attach(four_button);
	attach(five_button);
	attach(six_button);
	attach(seven_button);
	attach(eight_button);
	attach(nine_button);

	attach(two_button_p);
	attach(three_button_p);
	attach(four_button_p);
	attach(five_button_p);
	attach(six_button_p);
	attach(seven_button_p);
	attach(eight_button_p);
	attach(nine_button_p);



	//two_button.pw->labelcolor(FL_WHITE);


	attach(message);
	attach(message2);
	gui_main();
}


bool checkValidStrLength(string input, int n) {
	//std::cout << "n is : " << n << std::endl;
    if ((int)input.length() != n*2-1) //there should be exactly n*2 - 1 input characters
        return false;
    return true;
}

/**
 * Checks if the vector size is what it should be, and prints error messages if they aren't
 * @param {vector<int>} stack vector of ints tha represents the stack
 * @param {int} n number of pancakes on the stack
 * @returns {bool} false if not valid length, true if it is
 */
bool checkValidVectorLength(vector<int> stack, int n) {
    if ((int)stack.size() != n)
        return false;
    return true;
}

/**
 * Checks to see if the given vector of ints contains int_to_add already, and prints error messages
 * @param {vector<int>} stack vector of ints that reporesnts the stack
 * @param {int} int_to_add the int to add to the vector
 * @returns {bool} true if it contains a duplicate, false if no error/conflict
 */
bool checkDuplicateInput(vector<int> stack, int int_to_add) {
    bool exists = false;
    for (unsigned long int i = 0; i < stack.size(); i++)
        if (stack.at(i) == int_to_add)
            exists = true;
    
    return exists;
}

/**
 * Splits the string given into a vector<int>, and also checks for duplicate/incorrect numerical input
 */
vector<int> splitNumbers(string in, int n) {

	std::cout << in << std::endl;

    if (!checkValidStrLength(in, n)) return vector<int>(0);

	std::cout << in << std::endl;

    vector<int> stack;
    int index = 0;
    char c = 0;
    //char c = in.at(index++);
    try {
        while (c != 10 && c != 13) { //while the newline character is not the next character
            c = in.at(index++);
			std::cout << c << std::endl;
            if ((int)c - 48 < 0 || (int)c - 48 > 9)
                continue;
            int int_to_add = (int)c - 48;
            bool exists = checkDuplicateInput(stack, int_to_add);
            if (exists) return vector<int>(0); 

            stack.push_back(int_to_add);
            if (index == (int)in.length())
                break;
        }
    } catch (int e) { cerr << e << endl;}

    if (!checkValidVectorLength(stack, n)) return vector<int>(0);

    return stack;
}

void High_scores::next()
{
	init = initials.get_string();
	ord = order.get_string();
	if (ord.length() == 0 || ord.at(0) == 'r') { //random order
        vector<int> vals;
        for (int i = 0; i < num_pancakes; i++)
            vals.push_back(i+1);

        srand(time(NULL));

        while (vals.size() != 0) {
            int rand_ind = rand() % vals.size();
            stack.push_back(vals.at(rand_ind));
            vals.erase(vals.begin() + rand_ind);
        }

    } else
		stack = splitNumbers(string(ord), num_pancakes);
	
	if ((init=="")||(difficulty_level==0) || (num_pancakes == 0) || stack.size() == 0){
		Simple_window err_win{Point(100,100),600,400,"PANFLIPCAKE"};
		Text error_message{Point{50,200}, "Please make sure you entered your initials, the number of pancakes, a difficulty level,\n and a correct ordering"};
		//std::cout << "vector(0): " << stack.at(0) << std::endl;
		err_win.attach(error_message);
		err_win.wait_for_button();
	}
	else{
	
		hide();
		score = flip_screen(difficulty_level, stack);
	//vector<char> char_vec {difficulty(difficulty_level)};
	//Game_window(Point(100,100), 600, 400, "The Super Adder", char_vec, init);
	}
	
}

string High_scores::level_3()
{
	string word;	
	string text_3 = "#1: ";
	
	ifstream ert("scores_1.txt");
		
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_3.append(word);
				text_3.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_3.append(word);
				text_3.append("        ");
			} 
		} 
	}
	
	return text_3;
}

string High_scores::level_4()
{
	string word;
	string text_4 = "#2: ";
	ifstream ert;
	ert.open("scores_2.txt");
		
for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_4.append(word);
				text_4.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_4.append(word);
				text_4.append("        ");
			}  
		} 
	}
	
	return text_4;
}

string High_scores::level_5()
{
	string word;
	string text_5 = "#3: ";
	ifstream ert;
	ert.open("scores_3.txt");
	
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_5.append(word);
				text_5.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_5.append(word);
				text_5.append("        ");
			}  
		} 
	}
	
	return text_5;
}

string High_scores::level_6()
{
	string word;
	string text_6 = "#4: ";
	ifstream ert;
	ert.open("scores_4.txt");
	
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_6.append(word);
				text_6.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_6.append(word);
				text_6.append("        ");
			}  
		} 
	}
	
	return text_6;
}

string High_scores::level_7()
{
	string word;
	string text_7 = "#5: ";
	ifstream ert;
	ert.open("scores_5.txt");
	
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_7.append(word);
				text_7.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_7.append(word);
				text_7.append("        ");
			}  
		} 
	}
	
	return text_7;
}

















string High_scores2::level_3()
{
	string word;	
	string text_3 = "#1: ";
	
	ifstream ert("scores_1.txt");
		
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_3.append(word);
				text_3.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_3.append(word);
				text_3.append("        ");
			} 
		} 
	}
	
	return text_3;
}

string High_scores2::level_4()
{
	string word;
	string text_4 = "#2: ";
	ifstream ert;
	ert.open("scores_2.txt");
		
for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_4.append(word);
				text_4.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_4.append(word);
				text_4.append("        ");
			}  
		} 
	}
	
	return text_4;
}

string High_scores2::level_5()
{
	string word;
	string text_5 = "#3: ";
	ifstream ert;
	ert.open("scores_3.txt");
	
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_5.append(word);
				text_5.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_5.append(word);
				text_5.append("        ");
			}  
		} 
	}
	
	return text_5;
}

string High_scores2::level_6()
{
	string word;
	string text_6 = "#4: ";
	ifstream ert;
	ert.open("scores_4.txt");
	
	for(int i=0; i<10; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_6.append(word);
				text_6.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				text_6.append(word);
				text_6.append("        ");
			}  
		} 
	}
	
	return text_6;
}

string High_scores2::level_7(int newScore, string newName)
{
	string word;
	string text_7 = "#5: ";
	ifstream ert;
	ert.open("scores_5.txt");

	bool replaceScore;
	
	for(int i=0; i<2; i++)
	{
		if (i%2==0){
			if(ert>>word)
			{
				text_7.append(word);
				text_7.append(" ");
			} 
		}
		else{
			if(ert>>word)
			{
				replaceScore = atoi(word.c_str()) < newScore;
				text_7.append(word);
				text_7.append("        ");
			}  
		} 
	}
	
	return replaceScore ? string("#5: " + newName + "   " + to_string(newScore)) : text_7;
}

High_scores2::High_scores2(Point xy, int w, int h, const string& title, int newScore, string newName)
	: Window{xy,w,h,title},
	
	scores_title{Point {w/2-50, 50}, "HIGH SCORES"},
	
	initial_3{Point{w/2-50, 100}, level_3()},
	initial_4{Point{w/2-50, 120}, level_4()},
	initial_5{Point{w/2-50, 140}, level_5()},
	initial_6{Point{w/2-50, 160}, level_6()},
	initial_7{Point{w/2-50, 180}, level_7(newScore, newName)},
	
	quit_button(Point(w-70,0), 70, 20, "Quit", cb_quit),
	next_button{Point{(w/2-35), 300}, 70, 20, "Continue", [](Address, Address pw){reference_to<High_scores>(pw).next();}},
	
	init("")
{
	attach(next_button);
	attach(scores_title);
	attach(initial_3);
	attach(initial_4);
	attach(initial_5);
	attach(initial_6);
	attach(initial_7);
	attach(quit_button);

	gui_main();
}
/*
void new_scores(string add_init,double add_score, int difficulty_level)
{
	vector<string> scores_files{"scores_3.txt", "scores_4.txt", "scores_5.txt", "scores_6.txt", "scores_7.txt"};
	
	fstream ist(scores_files[difficulty_level-3], fstream::out| fstream::in);
	
	if(!ist) 
	{
		ist.close();
		ofstream ofs(scores_files[difficulty_level-3]);
		ofs.close();
		ist.open(scores_files[difficulty_level-3], fstream::out| fstream::in);
	}
	
	
	vector<double> score_list;
	vector<string> initial_list;
	double value;
	string word;
	
	for(int i=0; i<10; i++)
	{
			if(i%2==0){
				if(ist>>word) initial_list.push_back(word);
			}
			else{
				if(ist>>value) score_list.push_back(value);
			}
	}
	
	ist.close();
	
	score_list.push_back(add_score);
	initial_list.push_back(add_init);

	reverse(score_list.begin(), score_list.end());
	reverse(initial_list.begin(), initial_list.end());
	for (int i=0; i<score_list.size()-1; i++){	
		if(score_list[i]>score_list[i+1]){
			iter_swap(score_list.begin()+ i, score_list.begin() + i+1);
			iter_swap(initial_list.begin()+i, initial_list.begin() + i+1);
	}
	}
	reverse(score_list.begin(), score_list.end());
	reverse(initial_list.begin(), initial_list.end());
	
	ist.open(scores_files[difficulty_level-3]);
	
	if(score_list.size() < 6)
	{
		auto i {0};
		
		for(const int& j : score_list)
		{
			ist << fixed << setprecision(2) << initial_list[i] << ' ' << j << " ";
			++i;
		}
	}
	else
	{
		for(int i=0; i<5; i++)
		{
			ist << fixed << setprecision(2) << initial_list[i] << ' ' << score_list[i] << " ";
		}
	}
	
	ist.close();
}

vector<string> High_scores2::getScores(string newName, int newScore) {
	vector<string> scores_files{"scores_1.txt", "scores_2.txt", "scores_3.txt", "scores_4.txt", "scores_5.txt"};

	vector<int> scores;

	string word;

	vector<string> score_strings;


	string tempName = "";
	ifstream ert;
	
	for (int j = 0; j < scores_files.size(); j++) {
		ert.open(scores_files.at(j));
		for(int i=0; i<2; i++) {
			if (i%2==0) {
				if(ert>>word)
					tempName = word;
			}
			if (i%2==1){
				if(ert>>word) {
					scores.push_back(atoi(word.c_str()));
					score_strings.push_back(tempName + "   " + to_string(word));
				}
			}
		}
	}

	for (int i = 0; i < scores.size(); i++) {
		if (scores.at(i) < newScore) {
			score_strings.insert(score_strings.begin() + i, newName + "   " + to_string(newScore));
			score_strings.pop_back();

			ofstream ofs;
			ofs.open(scores_files.at(i));
			ofs << newName << "   " << newScore;
			ofs.close();

			return score_strings;
		}
	}

	return score_strings;
}

High_scores2::High_scores2(Point xy, int w, int h, const string& title, int score, string init)
	: Window{xy,w,h,title},
	
	scores_title{Point {w/2,100}, "HIGH SCORES"},
	message(Point(w/2, 200), string("Your score: " + to_string(score))),
	
	initial_3{Point{w/2, 300}, level_3()},
	initial_4{Point{w/2, 320}, level_4()},
	initial_5{Point{w/2, 340}, level_5()},
	initial_6{Point{w/2, 360}, level_6()},
	initial_7{Point{w/2, 380}, level_7()},
	
	quit_button(Point(w-70,0), 70, 20, "Quit", cb_quit),
	next_button{Point{(w/2-35), 200}, 70, 20, "Continue", [](Address, Address pw){reference_to<High_scores>(pw).next();}},*/