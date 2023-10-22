#include "Puzzle.hpp"

Puzzle::Puzzle(int size)
    :boardSize(size)
{
    matrix = Matrix(boardSize, Vector(boardSize));
    initialMatrix = Matrix(boardSize, Vector(boardSize));
    zeroI = zeroJ = boardSize - 1;
    setInitialMatrix();
}

void Puzzle::setInitialMatrix()
{
    int value = 0;
    for(int i = 0; i < boardSize; ++i)
        for(int j = 0; j < boardSize; ++j)
        {
            initialMatrix[i][j] = ++value;
            matrix[i][j] = value;
        }
    initialMatrix[zeroI][zeroJ] = 0;
    matrix[zeroI][zeroJ] = 0;
}

void Puzzle::shuffle()
{
    const int numOfInversions = 2 * boardSize;
    srand(time(0));
    for(int i = 0; i < numOfInversions ; ++i)
    {
        int i1, i2, j1, j2;
        do{
        i1 = rand() % boardSize;
        do{
            i2 = rand() % boardSize;
        }while(i1 == i2);
        j1 = rand() % boardSize;
        do{
            j2 = rand() % boardSize;
        }while(j1 == j2);
        
        }while(0 == matrix[i1][j1] || 0 == matrix[i2][j2]);

        std::swap(matrix[i1][j1], matrix[i2][j2]);
    }
}

int Puzzle::getNumber(int i, int j) const
{
    return matrix[i][j];
}

bool Puzzle::canMove(Direction dir)
{
    switch(dir)
    {
        case Up:
            return zeroI < boardSize - 1;
        case Left:
            return zeroJ < boardSize - 1;
        case Down:
            return zeroI > 0;
        case Right:
            return zeroJ > 0;
        default:
            return false;
    }
}

bool Puzzle::move(Direction dir)
{
    if(!canMove(dir))
        return false;
    switch(dir)
    {
        case Up:
            std::swap(matrix[zeroI][zeroJ], matrix[zeroI + 1][zeroJ]);
            ++zeroI;
            break;
        case Left:
            std::swap(matrix[zeroI][zeroJ], matrix[zeroI][zeroJ + 1]);
            ++zeroJ;
            break;
        case Down:
            std::swap(matrix[zeroI][zeroJ], matrix[zeroI - 1][zeroJ]);
            --zeroI;
            break;
        case Right:
            std::swap(matrix[zeroI][zeroJ], matrix[zeroI][zeroJ - 1]);
            --zeroJ;
    }
    return true;
}

bool Puzzle::isSolved()
{
    return matrix == initialMatrix;
}