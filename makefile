lifesim: cell.o main.o life_game.o
	g++  -std=c++11 -I include/ -o lifesim main.o life_game.o

life_game.o: source/life_game.cpp
	g++  -std=c++11 -I include/ -c source/life_game.cpp

life.o: source/life.cpp
	g++  -std=c++11 -I include/ -c source/life.cpp

main.o: main/main.cpp
	g++  -std=c++11 -I include/ -c main/main.cpp