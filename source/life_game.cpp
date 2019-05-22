#include "life_game.h"
#include <iostream>
#include <fstream>

life_game::life_game(std::string filename, int maxGen)
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
	//file >> std::noskipws;

	actual_gen = new Life(line, coll);
	char buffer;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < coll; j++)
		{
			file >> buffer;
			if(buffer == live_char)
			{
				actual_gen->get_biosphere(i+1,j+1).set_life(true);
				actual_gen->set_alive();
			}
		}
	}

	//std::cout << actual_gen->get_nCol() << " " << actual_gen->get_nCol() << "\n";
	/*
	for (int i = 1; i < actual_gen->get_nLin(); i++)
	{
		for (int j = 1; j < actual_gen->get_nCol(); j++)
		{
			std::cout << actual_gen->get_biosphere(i,j).get_status() << " ";
		}
		std::cout << "\n";
	}
	actual_gen->set_alive();
	generations.push_back( actual_gen->get_alive());
	*/
	file.close();

	max_gen = maxGen;
}

void life_game::update( void )
{
	actual_gen->update();
	generations.push_back(actual_gen->get_alive());
}

void life_game::render( void )
{
	std::cout << "geração " << turn_count << "\n" << *actual_gen << std::endl;
}

bool life_game::game_over( void )
{
	if( actual_gen->extinct() )
	{
		std::cout << "geração extinta" << std::endl;
		return true;
	}
	if( stable() )
	{
		return true;
	}
	if( max_gen != 0 && turn_count == max_gen )
	{
		std::cout << "LIMITE DE GERAÇÃO ATINGIDO - Geração atual:  " << turn_count << std::endl;
		return true;
	}
	
	turn_count++;

	return false;
}

bool life_game::stable( void )
{	
	if( generations.size() > 1 )
	{
		for( size_t i = 0; i < generations.size()-1; i++ )
		{
			if(	actual_gen->get_alive().size() == generations[i].size() )
				for( size_t j = 0; j < actual_gen->get_alive().size()-1; j++ )
				{
					if( !(actual_gen->get_alive()[j] == generations[i][j]) )
					{
						break;
					}
					else if( j == actual_gen->get_alive().size()-2 )
					{
						std::cout << "ESTABILIDADE DETECTADA geração atual igual a geração " << i+1 <<std::endl;
						return true;
					}
				}
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
				os << "#" << " ";
			else
				os << "-" << " ";
		}
		os << std::endl;
	}
	return os;
}
