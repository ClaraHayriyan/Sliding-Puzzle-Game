#include "MenuView.hpp"

MenuView::MenuView(Menu& menu)
: NUM_OF_CHOICES(menu.getNumOfChoices())
{
    startNcurses();
    drawMenuWindow();
}

void MenuView::startNcurses()
{
    initscr();
    refresh();
    noecho();
    curs_set(0);
}

void MenuView::drawMenuWindow()
{
    int HEIGHT = NUM_OF_CHOICES * 3;
    int WIDTH = 30;
    int Y = 4;
    int X = 20;
    menuWindow = newwin(HEIGHT, WIDTH, Y, X);
    refresh();
}

void MenuView::show(Menu& menu)
{
    int Y = 0;
    int X = 0;
    mvwaddstr(menuWindow, Y, X, "Choose the game mode");
    X = 9;
    for(int i = 0, Y = 2; i < NUM_OF_CHOICES; ++i, Y += 2)
        mvwaddstr(menuWindow, Y, X, menu.getChoice(i).data());
    drawArrow(currentChoice);
    wrefresh(menuWindow);
}

void MenuView::drawArrow(int i)
{
    int Y = 2 * i + 2;
    int X = 7;
    mvwprintw(menuWindow, Y, X, "->");
}

void MenuView::eraseArrow(int i)
{
    int Y = 2 * i + 2;
    int X = 7;
    mvwprintw(menuWindow, Y, X, "  ");
}

void MenuView::moveArrow(Dir dir)
{
    eraseArrow(currentChoice);
    switch(dir)
    {
        case up:
            --currentChoice;
            break;
        case down:
            ++currentChoice;
            break;
        default:
            break;
    }
    drawArrow(currentChoice);
}

void MenuView::hideMenu()
{
    wclear(menuWindow);
    wrefresh(menuWindow);
}

char MenuView::getInput()
{
    return wgetch(menuWindow);
}

MenuView::~MenuView()
{
    endwin();
}