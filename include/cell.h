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
        bool isAlive = false;
    public:
        bool GetStatus();
        Coordinate GetPosition();
        void SetStatus(bool state);
};

#endif