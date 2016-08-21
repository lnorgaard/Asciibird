CXX = clang++

CXX_FLAGS = -g -std=c++11 -pedantic -Wall -Wextra

showAsciimation: showAsciimation.cc Sprite.o Asciimation.o
	$(CXX) showAsciimation.cc -o showAsciimation $(CXX_FLAGS) Sprite.o Asciimation.o -lncurses
	
Asciimation.o: Asciimation.cc Asciimation.h
	$(CXX) Asciimation.cc -o Asciimation.o -c $(CXX_FLAGS)

Sprite.o: Sprite.cc Sprite.h
	$(CXX) Sprite.cc -o Sprite.o -c $(CXX_FLAGS)

clean: 
	rm -rf *.o showAsciimation

again: clean showAsciimation
