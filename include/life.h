#ifndef LIFE_H
#define LIFE_H

#include "cell.h"
#include <vector>
#include<iostream>

//! Game of Life's generation class
/*! Class used for storing a generation of Conway's Game of Life.
    \author Weverson Paulo (Versinho)
    */
class Life
{
    private:
        int nLin;
        int nCol;
        Cell **biosphere;
        std::vector<Coordinate> live;
    public:
        //! Basic constructor
        Life( int nlin = 0, int ncol = 0 );
        //! Basic destructor
        ~Life();


        void set_alive( void );
        //! Returns the amount of lines the generation has.
        int get_nLin()const {return nLin; }
        //! Returns the amount of collumns the generaion has.
        int get_nCol()const {return nCol; }
        //! Returns a Cell's reference in the generation's biosphere.
        Cell & get_biosphere(int i, int j) const { return biosphere[i][j]; }
        //! Returns a std::vector with the coordinates of the live cells in the generation.
        std::vector<Coordinate> get_alive( void )
        { return live; }
        //! Creates a new generation, based on the rules of the simulation.
        void update( void );
        //! Returns the amount of living neighbors among the passed parameters.
        int living_neighbors( int,int );
        //! Checks for Rule #1 of the simulation, based on the passed parameters (the number of living neighbors).
        bool rule1( int );
        //! Checks for Rule #2 of the simulation, based on the passed parameters (the number of living neighbors).
        bool rule2( int );
        //! Checks for Rule #3 of the simulation, based on the passed parameters (the number of living neighbors).
        bool rule3( int );
        //! Checks for Rule #4 of the simulation, based on the passed parameters (the number of living neighbors).
        bool rule4( int );
        //! Returns whether there are any live cells in the generation.
        bool extinct( void )
        { return live.empty(); }

        friend std::ostream & operator<<( std::ostream& os, const Life& gen );

};

#endif