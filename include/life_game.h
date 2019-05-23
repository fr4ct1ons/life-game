#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include<string>
#include "life.h"
#include"image_gen.h"

//! Color struct
/*! Basic Struct used to define a mix of RGB inputs.
	*/
typedef struct Color
{
	unsigned char r,g,b;
} Color;


//! life_game class
/*
	This class contains all methods and parameters recquired for running Conway's Game of Life.
	\author Weverson Paulo (Versinho) and Gabriel Lucena (fr4ct1ons)
	*/
class life_game{
	private:
		std::vector< std::vector<Coordinate> > generations;
		Life *actual_gen;
		int turn_count = 0;
		int max_gen = 0;
		imgen::Image *img_gen;
		std::string img_folder;
		std::string outfile;
		std::ofstream outstream;
		Color alive = {0, 0, 255};
		Color dead = {255, 255, 0};
	public:
		//! Default constructor
		/*! Starts an instance of Conway's Game of Life.
			\param filename - Name of the file used for input of the game's starting cells.
			\param folder - Folder used for saving the images.
			\param dead - Color representing the dead cells.
			\param alive - Color representing the alive cells.
			\param outf - File used for storing the game's generation log.
			\param maxGen - Limit of generations the program can have.
			\param img_blockSize - Size of the block used to represent a cell, when rendering the images.
			*/
		life_game(std::string filename, std::string folder,Color dead, Color alive, std::string outf, int maxGen = 0, int img_blockSize = 10);
		//! Update method
		/*! Creates a new generation.
			*/
		void update( void );
		//! Game over check
		/*! Checks if the game is finished running. In this case, if stability was detected, there are no alive cells left or if the limit of generations was hit.
			*/
		bool game_over( void );
		//! Render method
		/*! Renders the game state by printing in the terminal (and a file, if it was specified) the current game state and generates an image.
			*/
		void render( void );
		//! Stability check
		/*! Checks if the current generation is equal to a previous generation.
			*/
		bool stable( void );
};
#endif