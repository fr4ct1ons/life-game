#ifndef CELL_H
#define CELL_H
//! \authors: Weverson and Gabriel Lucena

#include<cstdlib>
//#include"life_game.h"
//! Coordinate class
/*! Simple class that contains a public X and Y position.
    */
class Coordinate
{
    public:
        unsigned int x, y;
        bool operator==(const Coordinate &rhs)
        {
            return (x == rhs.x) && (y == rhs.y);
        }
};
//! Cell class
/*! Class used for Conway's Game of Life.
    \author Weverson Paulo (Versinho)
    */
class Cell
{
    private:
        Coordinate position;
        bool isAlive = false;
        bool nextTurn;
    public:
        //! Returns if the cell is alive or not.
        bool get_status( void ) const { return isAlive; }
        //!Returns the position of the cell.
        Coordinate get_position( void ) const { return position; }
        //!Sets if the cell is alive or not.
        void set_status(bool state){ isAlive = state; }
        //!Sets if the cell will be alive or not in the next generation.
        void set_status_next_turn( bool state ){ nextTurn = state; }
        //!Sets if the cell is alive or not.
        void set_life(bool state){ isAlive = state; }
        //! Sets the cell's position in the biosphere.
        void set_position(size_t y, size_t x)
        {
            position.x = x;
            position.y = y;
        }
        //! Updates the cell to the next generation's state.
        void att( void ){ isAlive = nextTurn; }
};

#endif