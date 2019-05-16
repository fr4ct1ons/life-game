#include"life_game.h"

void LifeGame::SetRound()
{
    for(size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            biosphere[i][j].AssertLife;
        }
    }
}

void LifeGame::RenderGame()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if(biosphere[i][j].GetStatus())
                std::cout << "[#]";
            else
                std::cout << "[ ]";
        }
        std::cout << "\n";
    }
    
    std::cout << std::flush;
}

void LifeGame::TestGame()
{
    biosphere[1][1].SetStatus(true);
    biosphere[1][2].SetStatus(true);
    biosphere[2][2].SetStatus(true);
}

Cell LifeGame::At(size_t y, size_t x)
{
    return biosphere[y][x];
}
