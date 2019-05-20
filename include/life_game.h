#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "life.h"

class life_game{
	private:
		std::vector<std::vector<Coordinate>> generations;
		Life actual_gen;
		int turn_count = 0;
		int max_gen;
		char life_char;
	public:
		void initializer();

		void update( void );

		bool game_over( void );

		void render( void );

		bool stable( void );
};
#endif;