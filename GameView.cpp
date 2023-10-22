#include "GameView.hpp"

GameView::GameView(int size)
:boardSize(size)
{
    drawRulesWindow();
    drawFinalWindow();
    drawBoardWindow();
    yEmpty = boardSize;
    xEmpty = 3 * (boardSize - 1) + 1;
    keypad(boardWindow, true);
}

void GameView::drawRulesWindow()
{
    int Y = 6;
    int X = 40;
    int HEIGHT = 7;
    int WIDTH = 22;
    rulesWindow = newwin(HEIGHT, WIDTH, Y, X);
    refresh();
    X = 2;
    Y = 2;
    mvwprintw(rulesWindow, Y, X, "A, W, S, D to move");
    Y += 2;
    mvwprintw(rulesWindow, Y, X, "R to restart game");
    Y += 2;
    mvwprintw(rulesWindow, Y, X, "Q to quit");
    wrefresh(rulesWindow);
}

void GameView::drawFinalWindow()
{
    int Y = 16;
    int X = 20;
    int HEIGHT = 4;
    int WIDTH = 50;
    finalWindow = newwin(HEIGHT, WIDTH, Y, X);
    refresh();
}

void GameView::drawBoardWindow()
{
    int Y = 6;
    int X = 10;
    int HEIGHT = boardSize + 2;
    int WIDTH = 3 * boardSize + 2;
    boardWindow = newwin(HEIGHT, WIDTH, Y, X);
    refresh();
    box(boardWindow, 0, 0);
    refreshBoard();
}

void GameView::refreshBoard()
{
    wrefresh(boardWindow);
}

void GameView::print(Puzzle* puzzle)
{
    int y;
    int x;
    for(int i = 0; i < boardSize; ++i)
    {
        y = i + 1;
        for(int j = 0; j < boardSize; ++j)
        {
            x = 3 * j + 1;
            printNumber(y, x, puzzle->getNumber(i, j));
        }
    }
    eraseNumber(yEmpty, xEmpty);
    refreshBoard();
}

void GameView::printNumber(int y, int x, int number)
{
    mvwprintw(boardWindow, y, x, "%3d", number);
}

void GameView::eraseNumber(int y, int x)
{
    mvwaddstr(boardWindow, y, x, "   ");
    refreshBoard();
}

void GameView::move(Direction dir, Puzzle* puzzle)
{
    int i = yEmpty - 1;
    int j = (xEmpty - 1) / 3;
    printNumber(yEmpty, xEmpty, puzzle->getNumber(i, j));
    switch(dir)
    {
        case Up:
            ++yEmpty;
            break;
        case Left:
            xEmpty += 3;
            break;
        case Down:
            --yEmpty;
            break;
        case Right:
            xEmpty -= 3;
    }
    eraseNumber(yEmpty, xEmpty);
}

char GameView::getInput()
{
    return wgetch(boardWindow);
}

void GameView::clear()
{
    wclear(boardWindow);
    wclear(rulesWindow);
    wclear(finalWindow);
    wrefresh(boardWindow);
    wrefresh(rulesWindow);
    wrefresh(finalWindow);
}

void GameView::showCongratulations()
{
    box(finalWindow, 0, 0);
    int Y = 1;
    int X = 1;
    mvwaddstr(finalWindow, Y, X, "You won!");
    mvwaddstr(finalWindow, Y + 1, X, "Press R to restart or any other key to quit.");
    wrefresh(finalWindow);
}

void GameView::hideCongratulations()
{
    wclear(finalWindow);
    wrefresh(finalWindow);
}

GameView::~GameView()
{
    clear();
}
