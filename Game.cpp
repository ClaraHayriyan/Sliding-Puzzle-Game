#include "Game.hpp"

void Game::initialize(int size)
{
    puzzle = new Puzzle(size);
    view = new GameView(size);
}

void Game::start()
{
    puzzle->shuffle();
    view->print(puzzle);
}

void Game::move(Direction dir)
{
    if(puzzle->move(dir))
        view->move(dir, puzzle);
}

void Game::processInput()
{
    char ch = view->getInput();
    switch(ch)
    {
        case 'w':
            move(Up);
            break;
        case 'a':
            move(Left);
            break;
        case 's':
            move(Down);
            break;
        case 'd':
            move(Right);
            break;
        case 'r':
            start();
            break;
        case 'q':
            quit = true;
    }
}

void Game::play(int size)
{
    char key = 'r';
    initialize(size);
    quit = false;
    while(!quit && key == 'r')
    {
        start();
        while(!quit && !puzzle->isSolved())
        {
        processInput();
        }
        if(!quit)
        {
            view->showCongratulations();
            key = view->getInput();
            view->hideCongratulations();
        }
    }
    finish();
}

void Game::finish()
{
    delete view;
    delete puzzle;
}