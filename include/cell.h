#ifndef CELL_H
#define CELL_H
//! \authors: Weverson and Gabriel Lucena

#pragma once

#include<cstdlib>
//#include"life_game.h"

typedef struct Coordinate
{
    unsigned int x, y;
} Coordinate;

class Cell
{
    private:
        Coordinate position;
        bool isAlive = false;
        bool nextTurn;
    public:
        bool get_status( void ){ return isAlive; }

        Coordinate get_position( void ){ return position; }

        void set_status(bool state){ isAlive = state; }

        void set_status_next_turn( bool state ){ nextTurn = state; }

        void set_life(bool state){ isAlive = state; }

        void set_position(size_t y, size_t x)
        {
            position.x = x;
            position.y = y;
        }

        
        //void AssertLife(LifeGame *game);
        //int SurroundingCellsAlive(LifeGame *game);
};

#endif