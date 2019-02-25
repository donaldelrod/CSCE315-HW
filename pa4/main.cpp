#include "flip_screen.cpp"
#include "Splash.cpp"

int main()
{
	int score = 0;
	Splash_window splash_window(tl, win_width, win_height, win_title);
	score = splash_window.score;
	High_scores2(tl, win_width, win_height, win_title, score, "dpe");
	//vector<int> v = {1,2,3,4,5};
	//score = flip_screen(hs_screen.getDiff(), hs_screen.getStack()); //##these values are harcoded, pass in the difficulty, then vector
}