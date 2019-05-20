#include"life_game.h"
#include<string>

int main(int argc, char const *argv[])
{

    std::string inputcfg;

    life_game myGame(inputcfg);

    while (myGame.game_over())
    {
        myGame.update();
        myGame.render();
    }
    

    return 0;
}
