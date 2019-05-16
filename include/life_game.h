//#ifndef LIFE_GAME_H
//#define LIFE_GAME_H

#pragma once
#include "cell.h"
#include<iostream>

class LifeGame
{
    private:
        Cell **biosphere;
        bool gameOver = false;
        int turnCount = 0;
        size_t width, height;
    public:
        LifeGame(size_t newWidth, size_t newHeight)
        {
            width = newWidth;
            height = newHeight;

            biosphere = new Cell*[height];
            for(size_t i = 0; i < height; i++)
                biosphere[i] = new Cell[width];

            for(size_t i = 0; i < height; i++)
                for (size_t j = 0; j < width; j++)
                {
                    biosphere[i][j].SetPosition(i,j);
                }
        }
        void TestGame();
        void RenderGame();
        void SetRound();
        bool GameOver();
        Cell At(size_t y, size_t x);
};


//#endif