main: Splash.cpp
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lfltk -lfltk_images -lX11 -ljpeg -o main Graph.o Window.o GUI.o Simple_window.o Splash.cpp combined.cpp
clean:
	rm main