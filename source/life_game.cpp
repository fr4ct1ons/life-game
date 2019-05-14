#include"life_game.h"
#include<iostream>

void LifeGame::SetRound()
{
    RenderGame();
}

void LifeGame::RenderGame()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if(biosphere[i][j].GetStatus())
                std::cout << "[+]";
            else
                std::cout << "[#]";
        }
        std::cout << "\n";
    }
    
    std::cout << std::flush;
}
