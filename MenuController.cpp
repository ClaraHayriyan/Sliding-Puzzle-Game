#include "MenuController.hpp"

MenuController::MenuController()
:view(menu)
{}

void MenuController::move(Dir dir)
{
    if(menu.changeCurrChoice(dir))
        view.moveArrow(dir);
}

char MenuController::processInput()
{
    char key = view.getInput();
    switch(key)
    {
        case 'w':
            move(up);
            break;
        case 's':
            move(down);
            break;
    }
    return key;
}

int MenuController::choose()
{
    view.show(menu);
    char key;
    do{
        key = processInput();
    }while(key != '\n');
    view.hideMenu();
    return menu.getCurrChoice();
}
