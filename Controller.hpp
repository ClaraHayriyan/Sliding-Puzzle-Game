#ifndef COURSE_PROJECT_CONTROLLER
#define COURSE_PROJECT_CONTROLLER

#include "Game.hpp"
#include "MenuController.hpp"
#include <iostream>

class Controller
{
private:
    Game game;
    MenuController menuController;
    bool quit = false;
    int gameModes[4] { 3, 4, 5, 0 };

private:
    int getGameMode();
    
public:
    Controller() {}
    ~Controller() {}
    void play();
};

#endif // COURSE_PROJECT_CONTROLLER
