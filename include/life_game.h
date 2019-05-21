#ifndef LIFE_GAME_H
#define LIFE_GAME_H
#include<string>
#include "life.h"

class life_game{
	private:
		std::vector< std::vector<Coordinate> > generations;
		Life *actual_gen;
		int turn_count = 0;
		int max_gen;
	public:
		life_game(std::string filename);

		void initializer();

		void update( void );

		bool game_over( void );

		void render( void );

		bool stable( void );
};
#endif