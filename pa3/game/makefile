# makefile

# Add your executable to the tests command so that in compiles along with the rest of the unit testing code
# Please name your executable in the form of test_(function number according to document)

main: Main.cpp
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o main Board.h Main.cpp find_solution.o -lncurses++ -lmenu -lpanel -lform -lutil -lncurses
tests: tests.cpp
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o tests -lcurses tests.cpp find_solution.o
	
part1_test: Part_One_Test_Main.cpp
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part1_test Part_One_Test_Main.cpp -lncurses++ -lmenu -lpanel -lform -lutil -lncurses 	

part2_test:
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part2_test test_part2_main.cpp -lncurses++ -lmenu -lpanel -lform -lutil -lncurses 

part4_test:
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part4_test TestDisplayScores.cpp -lncurses++ -lmenu -lpanel -lform -lutil -lncurses

part5_test:
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part5_test test_part5_main.cpp find_solution.o -lncurses++ -lmenu -lpanel -lform -lutil -lncurses 

part7_test: Test_AI_Main.cpp
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part7_test Test_AI_Main.cpp -lncurses++ -lmenu -lpanel -lform -lutil -lncurses 

part8_test:
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -o part8_test TestGameOver.cpp -lncurses++ -lmenu -lpanel -lform -lutil -lncurses

clean_tests:
	rm tests

clean:
	rm main tests part2_test part5_test part4_test part8_test part7_test part1_test
