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

        bool rule1( int );
        bool rule2( int );
        bool rule3( int );
        bool rule4( int );

        bool extinct( void )
        { return live.empty(); }

        friend std::ostream& operator<<( std::ostream& os, const Life& gen );

};

#endif