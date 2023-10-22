#include "Menu.hpp"

bool Menu::changeCurrChoice(Dir dir)
{
    switch(dir)
    {
        case up:
            if(0 == currentChoice)
                return false;
            --currentChoice;
            break;
        case down:
            if(NUM_OF_CHOICES - 1 == currentChoice)
                return false;
            ++currentChoice;
            break;
        default:
            return false;
    }
    return true;
}

int Menu::getNumOfChoices() const
{
    return NUM_OF_CHOICES;
}

int Menu::getCurrChoice() const
{
    return currentChoice;
}

Text Menu::getChoice(int i) const
{
    return choices[i];
}