#ifndef LIFE_GAME_H
#define LIFE_GAME_H

class life_game{
	private:
		std::vector<Coordinates> *generations;
		Life actual_gen;
		int turn_count = 0;
		int max_gen;
		char life_char;
	public:
		void initializer();
		void update();
		bool game_over();
		void render();
};
#endif;