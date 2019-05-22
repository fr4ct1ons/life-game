#include"life_game.h"
#include"interface.h"
#include<string>
#include<chrono>
#include<thread>

int main(int argc, char const *argv[])
{
    size_t blockSize = 10;
    std::string inputcfg;
    std::string outputFolder("");
    int maxGen = 0;
    std::chrono::seconds fps(1);
    AssertInitialization(argc, argv, &blockSize, &outputFolder, &inputcfg, &maxGen, &fps);
    life_game myGame(inputcfg, outputFolder, maxGen, blockSize);

    myGame.render();
    while (!myGame.game_over())
    {
        std::this_thread::sleep_for(fps);
        myGame.update();
        myGame.render();
    }
    

    return 0;
}
