#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include <vector>

class Life
{
    private:
        int nLin;
        int nCol;
        Cell **biosphere;
        std::vector<Coordinate> live;
    public:
        Life( int nlin = 0, int ncol = 0 );
        ~Life();

        void set_alive( std::vector<Coordinate> alive );

        std::vector<Coordinate> get_alive( void )
        { return live; }

        void update( void );

        int living_neighbors( Coordinate );

        // retornam true se o estado da celular mudar, e false c.c. 
        bool rule1( Cell );
        bool rule2( Cell );

        void rule3( Cell );
        void rule4( Cell );

        bool stable( void );

        bool extinct( void )
        { return live.empty(); }

};

#endif