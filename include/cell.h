//#ifndef CELL_H
//#define CELL_h
//Authors: Weverson and Gabriel Lucena

#pragma once

#include<cstdlib>
#include"life_game.h"

typedef struct Coordinate
{
    unsigned int x, y;
} Coordinate;

class Cell
{
    private:
        Coordinate position;
        bool isAlive = false;
        bool nextTurn = NULL;
    public:
        bool GetStatus();
        Coordinate GetPosition();
        void SetStatus(bool state);
        void SetPosition(size_t y, size_t x);
        void AssertLife(LifeGame *game);
        int SurroundingCellsAlive(LifeGame *game);
};

//#endif