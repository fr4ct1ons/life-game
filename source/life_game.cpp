#include "life_game.h"

void life_game::update( void )
{
	actual_gen.update();
}

void life_game::render( void )
{
	std::cout << "geração " << turn_count+1 << << actual_gen << std::endl;
}

bool life_game::game_over( void )
{
	if( actual_gen.extinct() )
		return true;
	if( stable() )
	{
		std::cout << "Detectada estabilidade, geração atual igual a geração " << turn_count+1 << std::endl;
		return true;
	}
	if( turn_count == max_gen )
		return true
	turn_count++;
	return false;
}

bool life_game::stable( void )
{	
	for( int i = 0; i < generations.size(); i++ )
	{
		if( actual_gen.get_alive() == generations[i] )
		{
			return true;
		}
	}
	return false;
}

std::ostream& operator<<( std::ostream& os, const Life& gen )
{
	for( int i = 0; i < (gen.nLin-2); i++ )
	{
		for( int j = 0; j < (gen.nCol-2); j++)
		{
			if( gen.biosphere[i+1][j+1].get_status )
				os << life_char;
			else
				os << "-";
		}
		os << std::endl;
	}
	return os;
}