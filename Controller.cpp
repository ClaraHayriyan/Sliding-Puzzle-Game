#include "Controller.hpp"

void Controller::play()
{
    while(!quit)
    {
        int boardSize = getGameMode();
        if(boardSize)
            game.play(boardSize);
        else
            quit = true;
    }
}

int Controller::getGameMode()
{
    int choice = menuController.choose();
    return gameModes[choice];
}
