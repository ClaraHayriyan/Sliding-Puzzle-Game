#ifndef COURSE_PROJECT_GAME_VIEW
#define COURSE_PROJECT_GAME_VIEW

#include "ncurses.h"
#include "Puzzle.hpp"

class GameView
{
private:
    WINDOW* boardWindow;
    WINDOW* rulesWindow;
    WINDOW* finalWindow;
    const int boardSize;
    int yEmpty;
    int xEmpty;

private:
    void drawRulesWindow();
    void drawFinalWindow();
    void drawBoardWindow();
    void refreshBoard();
    void printNumber(int y, int x, int number);
    void eraseNumber(int y, int x);
    void clear();

public:
    GameView(int size);
    ~GameView();
    void print(Puzzle*);    
    void move(Direction, Puzzle*);
    char getInput();
    void showCongratulations();
    void hideCongratulations();
};

#endif // COURSE_PROJECT_GAME_VIEW