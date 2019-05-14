#include"cell.h"

bool Cell::GetStatus() { return isAlive; }

Coordinate Cell::GetPosition() { return position; }

void Cell::SetStatus(bool state)
{
    isAlive = state;
}