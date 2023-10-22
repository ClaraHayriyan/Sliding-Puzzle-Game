#ifndef COURSE_PROJECT_MENU_CONTROLLER
#define COURSE_PROJECT_MENU_CONTROLLER

#include "Menu.hpp"
#include "MenuView.hpp"

class MenuController
{
private:
    Menu menu;
    MenuView view;

private:
    char processInput();
    void move(Dir);

public:
    MenuController();
    ~MenuController() {}
    int choose();
};


#endif // COURSE_PROJECT_MENU_CONTROLLER
