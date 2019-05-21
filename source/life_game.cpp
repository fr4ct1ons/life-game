#include "life_game.h"
#include <iostream>
#include <fstream>

life_game::life_game(std::string filename)
{
	std::ifstream file(filename);
	if(!file)
	{
		std::cout << "Error opening file, aborting program";
		std::exit(1);
	}

	int line, coll;
	char live_char;
	file >> line;
	file >> coll;
	file >> live_char;
	file >> std::noskipws;

	actual_gen = new Life(line, coll);

	char buffer;
	for (int i = 1; i < actual_gen->get_nLin(); i++)
	{
		for (int j = 1; j < actual_gen->get_nCol(); j++)
		{
			file >> buffer;
			if(buffer == live_char)
				actual_gen->get_biosphere(i, j).set_life(true);
			else
				actual_gen->get_biosphere(i, j).set_life(false);
		}
	}

	//std::cout << actual_gen->get_nCol() << " " << actual_gen->get_nCol() << "\n";

	for (int i = 1; i < actual_gen->get_nLin(); i++)
	{
		for (int j = 1; j < actual_gen->get_nCol(); j++)
		{
			std::cout << actual_gen->get_biosphere(i,j).get_status() << " ";
		}
		std::cout << "\n";
	}
	set_alive();
	
	
	file.close();
}

void life_game::update( void )
{
	actual_gen->update();
	generations.push_back(actual_gen->get_alive());
}

void life_game::render( void )
{
	std::cout << "geração " << turn_count+1 << "\n" << *actual_gen << std::endl;
}

bool life_game::game_over( void )
{
	if( actual_gen->extinct() )
		return true;
	if( stable() )
	{
		std::cout << "Detectada estabilidade, geração atual igual a geração " << std::endl;
		return true;
	}
	if( turn_count == max_gen )
		return true;
	
	turn_count++;

	return false;
}

bool life_game::stable( void )
{	
	for( size_t i = 0; i < generations.size(); i++ )
	{
		for( size_t j = 0; j < actual_gen->get_alive().size(); j++)
			if( !(actual_gen->get_alive()[j] == generations[i][j]) )
			{
				break;
			}
	}
	return false;
}

std::ostream& operator<<( std::ostream& os, const Life& gen )
{
	//Life *gen = &gen2;
	for( int i = 0; i < (gen.get_nLin()-2); i++ )
	{
		for( int j = 0; j < (gen.get_nCol()-2); j++)
		{
			if( gen.get_biosphere(i+1, j+1).get_status() )
				os << life_char << " ";
			else
				os << "-" << " ";
		}
		os << std::endl;
	}
	return os;
}
