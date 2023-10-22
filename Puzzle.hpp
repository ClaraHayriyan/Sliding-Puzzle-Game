#ifndef COURSE_PROJECT_PUZZLE
#define COURSE_PROJECT_PUZZLE

#include <iostream>
#include <vector>

enum Direction { Up, Left, Down, Right };

class Puzzle
{
    using Vector = std::vector<int>;
    using Matrix = std::vector<Vector>;
    
private:
    const int boardSize;
    Matrix matrix;
    Matrix initialMatrix;
    int zeroI;
    int zeroJ;

private:
    void setInitialMatrix();
    bool canMove(Direction);

public:
    Puzzle(int size);
    ~Puzzle() {}
    int getNumber(int, int) const;
    void shuffle();
    bool move(Direction);
    bool isSolved();
};

#endif // COURSE_PROJECT_PUZZLE