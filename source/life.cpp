#include "life.h"


Life::Life( int nlin, int ncol )
	//: nLin{nlin+2}, nCol{ncol+2}
{
	nLin = nlin + 2;
	nCol = ncol + 2;
	biosphere = new Cell*[nLin];
  	for( size_t i = 0; i < nLin; i++ )
  		biosphere[i] = new Cell[nCol];
   	for(size_t i = 0; i < nLin; i++)
		for (size_t j = 0; j < nCol; j++)
			biosphere[i][j].set_position(i,j);
}

Life::~Life()
{
	for(int i = 0; i < nLin; i++) 
      delete[] biosphere[i]; 

   	delete[] biosphere; 
}

/*void Life::set_alive( std::vector<Coordinate> alive )
{
  	live = alive;
  	for( int i = 0; i < alive.size(); i++ )
 		biosphere[alive[i].x + 1][alive[i].y + 1].set_life(true); 
}*/

void Life::set_alive( void )
{
	Coordinate coor;
	live.clear();
  	for( int i = 0; i < nLin-2; i++ )
  		for( int j = 0; j < nCol-2; j++ )
	 			if( biosphere[i + 1][j + 1].get_status() )
		 		{
		 			coor.x = i;
		 			coor.y = j;
		 			live.push_back(coor); 
		 		}
}

// CALCULA O NUMERO DE VIZINHAS VIVAS DE UMA CELULA
int Life::living_neighbors( int x, int y )
{
	int count = 0;
	if(	biosphere[x][y-1].get_status() )//esquerda
		count++;

	if( biosphere[x][y+1].get_status() )//direita
		count++;

	if( biosphere[x-1][y].get_status() )//cima
		count++;

	if( biosphere[x+1][y].get_status() )//baixo
		count++;

	if( biosphere[x-1][y-1].get_status() )//canto superior esquerdo
		count++;

	if( biosphere[x+1][y-1].get_status() )//canto inferior esquerdo
		count++;

	if( biosphere[x-1][y+1].get_status() )//canto superior direito
		count++;

	if( biosphere[x+1][y+1].get_status() )//canto inferior direito
		count++;


	return count;
}

//Se uma celula esta viva, mas o numero de vizinhos vivos e menor ou igual a um, na proxima geracao a celula morrera de solidao.
bool Life::rule1( int ln )
{
	return not(ln <= 1); 
}

//Se uma celula esta viva e tem quatro ou mais vizinhos vivos, na proxima geracao a celula morrera sufocada devido a superpopulacao
bool Life::rule2( int ln )
{
	return not(ln >= 4);
}

//Uma celula viva com dois ou tres vizinhos vivos, na proxima geracao permanecera viva.
bool Life::rule3( int ln )
{
	return (ln == 2 or ln == 3);
}

// Se uma celula esta morta, entao na proxima geracao ela se tornara viva se possuir exatamente tres vizinhos vivos. Se possuir uma quantidade de vizinhos vivos diferente de tres, a celula permanecera morta
bool Life::rule4( int ln )
{
	return ln==3;
}

void Life::update( void )
{
	int ln = 0;
	//setando o proximo turno das células vivas
	for( int i = 0; i < nLin-2; i++ )
		for( int j = 0; j < nCol-2; j++)
		{
			ln = living_neighbors( i+1, j+1 );
			if( biosphere[i+1][j+1].get_status() )
				biosphere[i+1][j+1].set_status_next_turn( rule1(ln) && rule2(ln) && rule3(ln));
			else
			{
				if( i == 2 and j == 0)
					std::cout << "LN :  >>>  : " << ln <<std::endl;
				biosphere[i+1][j+1].set_status_next_turn(rule4(ln) );
			}
		}

	//aplicando o update
	//std::vector<Coordinate> alive;
	for( int i = 0; i < (nLin-2); i++ )
		for( int j = 0; j < (nCol-2); j++ )
		{
			biosphere[i+1][j+1].att();
		}
		set_alive(); 
	//live = alive;
}
	

/*std::ostream& operator<<( std::ostream& os, const Life& gen )
{
	for( int i = 0; i < (gen.nLin-2); i++ )
	{
		for( int j = 0; j < (gen.nCol-2); j++)
		{
			if( gen.biosphere[i+1][j+1].get_status )
				os << "*";
			else
				os << "-";
		}
		os << std::endl;
	}
	return os;
}*/

/*bool operator==(const Coordinate &lhs, const Coordinate &rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}*/

/*bool operator==( Life & lhs, Life & rhs )
{
	return lhs.get_alive() == rhs.get_alive();
}
*/

