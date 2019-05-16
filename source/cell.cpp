#include"cell.h"

bool Cell::GetStatus() { return isAlive; }

Coordinate Cell::GetPosition() { return position; }

void Cell::SetStatus(bool state)
{
    isAlive = state;
}

void Cell::SetPosition(size_t y, size_t x)
{
    position.x = x;
    position.y = y;
}

void Cell::AssertLife(LifeGame *game)
{
    if(isAlive)
    {
        
    }
}

int Cell::SurroundingCellsAlive(LifeGame *game)
{
    
}