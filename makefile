lifesim: cell.o main.o life_game.o
	g++ -Wall -std=c++11 -I include/ -o lifesim cell.o main.o life_game.o

cell.o: source/cell.cpp
	g++ -Wall -std=c++11 -I include/ -c source/cell.cpp

life_game.o: source/life_game.cpp
	g++ -Wall -std=c++11 -I include/ -c source/life_game.cpp

life.o: source/life.cpp
	g++ -Wall -std=c++11 -I include/ -c source/life.cpp

main.o: main/main.cpp
	g++ -Wall -std=c++11 -I include/ -c main/main.cpp