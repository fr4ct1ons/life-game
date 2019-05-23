lifesim:  lodepng.o life.o life_game.o image_gen.o main.o
	g++ -Wall -ggdb3 -std=c++11 -I include/ -o lifesim main.o life_game.o life.o image_gen.o lodepng.o

lodepng.o: source/lodepng.cpp
	g++ -Wall -ggdb3 -std=c++11 -I include/ -c source/lodepng.cpp

life.o: source/life.cpp
	g++ -Wall -ggdb3 -std=c++11 -I include/ -c source/life.cpp

life_game.o: source/life_game.cpp
	g++ -Wall -ggdb3 -std=c++11 -I include/ -c source/life_game.cpp

image_gen.o:
	g++ -Wall -ggdb3 -std=c++11 -I include/ -c source/image_gen.cpp

main.o: main/main.cpp
	g++ -Wall -ggdb3 -std=c++11 -I include/ -c main/main.cpp