#include "life_game.h"
#include <iostream>
#include <fstream>

life_game::life_game(std::string filename, std::string folder, Color newDead, Color newAlive, /* DEFAULTS*/ int maxGen, int img_blockSize)
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
	file >> buffer;
	for (int i = 0; i < line + 1; i++)
	{
		for (int j = 0; j < coll + 1; j++)
		{
			if(file >> buffer)
			{
				if(buffer == live_char)
					actual_gen->get_biosphere(i+1,j+1).set_life(true);
				else if (buffer == '\n')
					break;
				else
					actual_gen->get_biosphere(i+1,j+1).set_life(false);

				actual_gen->set_alive();
			}
		}
	}

	//std::cout << actual_gen->get_nCol() << " " << actual_gen->get_nCol() << "\n";
	
	/*for (int i = 1; i < actual_gen->get_nLin(); i++)
	{
		for (int j = 1; j < actual_gen->get_nCol(); j++)
		{
			std::cout << actual_gen->get_biosphere(i,j).get_status() << " ";
		}
		std::cout << "\n";
	}*/
	actual_gen->set_alive();
	generations.push_back( actual_gen->get_alive());
	
	file.close();

	alive = newAlive;
	dead = newDead;
	img_gen = new imgen::Image(coll, line, img_blockSize);
	img_folder = folder;
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
	int bSize = img_gen->GetBlockSize();
	for(int i = 0; i < actual_gen->get_nLin() - 2; i++)
	{
		for(int j = 0; j < actual_gen->get_nCol() -2; j++)
		{
			//std::cout << "Pintando pixel em " << i * bSize << " " << j * bSize << std::endl;
			if(actual_gen->get_biosphere(i + 1, j + 1).get_status())
				img_gen->PaintBlock(j * bSize, i * bSize, alive.r, alive.g, alive.b);
			else
				img_gen->PaintBlock(j * bSize, i * bSize, dead.r, dead.g, dead.b);
		}
	}
	
	img_gen->SaveFile(img_folder + "life_game_" + std::to_string(turn_count) + ".pnm");
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
