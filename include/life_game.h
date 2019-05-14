#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "cell.h"
#include<cstdlib>

class LifeGame
{
    private:
        Cell **biosphere;
        bool gameOver = false;
        int turnCount = 0;
        size_t width, height;

        void RenderGame();
    public:
        LifeGame::LifeGame(size_t newWidth, size_t newHeight)
        {
            width = newWidth;
            height = newHeight;

            biosphere = new Cell*[height];
            for(size_t i = 0; i < height; i++)
                biosphere[i] = new Cell[width];
            
        }

        void SetRound();
};


#endif