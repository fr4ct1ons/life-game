#include "life.h"
Life::Life( int nlin, int ncol )
	: nLin{nlin+2}, nCol{ncol+2}
{
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

void Life::set_alive( std::vector<Coordinate> alive )
{
  	live = alive;
  	for( int i = 0; i < alive.size(); i++ )
 	biosphere[alive[i].x + 1][alive[i].y + 1].set_life(true); 
}
// CALCULA O NUMERO DE VIZINHAS VIVAS DE UMA CELULA
int Life::living_neighbors( Coordinate coor )
{
	coor.x++;
	coor.y++;
	int count = 0;
	if(	biosphere[coor.x][coor.y-1].get_status() )//esquerda
		count++;
	if( biosphere[coor.x][coor.y+1].get_status() )//direita
		count++;
	if( biosphere[coor.x-1][coor.y].get_status() )//cima
		count++;
	if( biosphere[coor.x+1][coor.y].get_status() )//baixo
		count++;
	if( biosphere[coor.x-1][coor.y-1].get_status() )//canto superior esquerdo
		count++;
	if( biosphere[coor.x+1][coor.y-1].get_status() )//canto inferior esquerdo
		count++;
	if( biosphere[coor.x-1][coor.y+1].get_status() )//canto superior direito
		count++;
	if( biosphere[coor.x+1][coor.y+1].get_status() )//canto inferior direito
		count++;
	return count;
}

//Se uma celula esta viva, mas o numero de vizinhos vivos e menor ou igual a um, na proxima geracao a celula morrera de solidao.
bool Life::rule1( Cell cell )
{
	if( living_neighbors( cell.get_position() ) <= 1 )
	{
		cell.set_status_next_turn( false );
		return true;
	}
	return false;	
}

//Se uma celula esta viva e tem quatro ou mais vizinhos vivos, na proxima geracao a celula morrera sufocada devido a superpopulacao
bool Life::rule2( Cell cell )
{
	if( living_neighbors( cell.get_position() ) >= 4 )
	{
		cell.set_status_next_turn( false );
		return true;
	}
	return false;
}

//Uma celula viva com dois ou tres vizinhos vivos, na proxima geracao permanecera viva.
void Life::rule3( Cell cell )
{
	if( cell.get_status() and (living_neighbors( cell.get_position() ) == 2 or living_neighbors( cell.get_position() ) == 3) )
		cell.set_status_next_turn( true );
	else
		cell.set_status_next_turn( false );
}

// Se uma celula esta morta, entao na proxima geracao ela se tornara viva se possuir exatamente tres vizinhos vivos. Se possuir uma quantidade de vizinhos vivos diferente de tres, a celula permanecera morta
void Life::rule4( Cell cell )
{
	if( not(cell.get_status()) and living_neighbors( cell.get_position() ) == 3 )
		cell.set_status_next_turn( true );
}

void Life::update( void )
{
	//setando o proximo turno das células vivas
	for( int i = 0; i < live.size(); i++ )
	{
		if( rule1( biosphere[live[i].x][live[i].y] ) )
			continue;
		else if ( rule2( biosphere[live[i].x][live[i].y] ) )
			continue;
		else	
			rule3( biosphere[live[i].x][live[i].y] );
	}

}

