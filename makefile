lifesim: life.o life_game.o image_gen.o main.o
	g++  -std=c++11 -I include/ -o lifesim main.o life_game.o life.o image_gen.o

life.o: source/life.cpp
	g++  -std=c++11 -I include/ -c source/life.cpp

life_game.o: source/life_game.cpp
	g++  -std=c++11 -I include/ -c source/life_game.cpp

image_gen.o:
	g++  -std=c++11 -I include/ -c source/image_gen.cpp

main.o: main/main.cpp
	g++  -std=c++11 -I include/ -c main/main.cpp