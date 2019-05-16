#include"life_game.h"

int main(int argc, char const *argv[])
{
    LifeGame newGame(4, 4);
    newGame.TestGame();
    newGame.RenderGame();
    //newGame.SetRound();

    return 0;
}
