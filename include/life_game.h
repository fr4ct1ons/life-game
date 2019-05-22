#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include<string>
#include "life.h"
#include"image_gen.h"

class life_game{
	private:
		std::vector< std::vector<Coordinate> > generations;
		Life *actual_gen;
		int turn_count = 0;
		int max_gen = 0;
		imgen::Image *img_gen;
		std::string img_folder;
	public:
		life_game(std::string filename, std::string folder, int maxGen = 0, int img_blockSize = 10);

		void initializer();

		void update( void );

		bool game_over( void );

		void render( void );

		bool stable( void );
};
#endif