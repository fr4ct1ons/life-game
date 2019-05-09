lifesim: cell.o main.o
	g++ -Wall -std=c++11 -I include/ -o lifesim cell.o main.o

cell.o: source/cell.cpp
	g++ -Wall -std=c++11 -I include/ -c source/cell.cpp

main.o: main/main.cpp
	g++ -Wall -std=c++11 -I include/ -c main/main.cpp