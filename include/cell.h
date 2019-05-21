#ifndef CELL_H
#define CELL_H
//! \authors: Weverson and Gabriel Lucena

#pragma once

#include<cstdlib>
//#include"life_game.h"

class Coordinate
{
    public:
        unsigned int x, y;
        bool operator==(const Coordinate &rhs)
        {
            return (x == rhs.x) && (y == rhs.y);
        }
};

class Cell
{
    private:
        Coordinate position;
        bool isAlive = false;
        bool nextTurn;
    public:
        bool get_status( void ) const { return isAlive; }

        Coordinate get_position( void ) const { return position; }

        void set_status(bool state){ isAlive = state; }

        void set_status_next_turn( bool state ){ nextTurn = state; }

        void set_life(bool state){ isAlive = state; }

        void set_position(size_t y, size_t x)
        {
            position.x = x;
            position.y = y;
        }
        void att( void ){ isAlive = nextTurn; }
};

#endif