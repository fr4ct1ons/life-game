#ifndef CELL_H
#define CELL_h


typedef struct Coordinate
{
    unsigned int x, y;
} Coordinate;

class Cell
{
    private:
        Coordinate position;
        bool isAlive;
    public:
        bool GetStatus();
        Coordinate GetPosition();
};

#endif