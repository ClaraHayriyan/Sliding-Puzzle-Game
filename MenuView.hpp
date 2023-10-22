#ifndef COURSE_PROJECT_MENU_VIEW
#define COURSE_PROJECT_MENU_VIEW

#include "ncurses.h"
#include "Menu.hpp"

class MenuView
{
private:
    WINDOW* menuWindow;
    const int NUM_OF_CHOICES;
    int currentChoice = 0;

private:
    void startNcurses();
    void drawMenuWindow();
    void drawArrow(int);
    void eraseArrow(int);

public:
    MenuView(Menu&);
    ~MenuView();
    void show(Menu&);
    void hideMenu();
    void moveArrow(Dir);
    char getInput();
};

#endif // COURSE_PROJECT_MENU_VIEW
