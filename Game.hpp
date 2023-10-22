#ifndef COURSE_PROJECT_GAME
#define COURSE_PROJECT_GAME

#include "Puzzle.hpp"
#include "GameView.hpp"

class Game
{
private:
    Puzzle* puzzle;
    GameView* view;
    bool quit = false;

private:
    void initialize(int size);
    void start();
    void move(Direction);
    void processInput();
    void finish();

public:
    Game() {}
    ~Game() {}
    void play(int size);
};

#endif // COURSE_PROJECT_GAME