#ifndef COURSE_PROJECT_MENU
#define COURSE_PROJECT_MENU

#include "ncurses.h"
#include <string>
#include <vector>

enum Dir { up, down };
using Text = std::string;
using Choices = std::vector<std::string>;

class Menu
{
private:
    int currentChoice = 0;
    const int NUM_OF_CHOICES = 4;
    Choices choices { "3x3", "4x4", "5x5", "Quit" };
    
public:
    Menu() {}
    ~Menu() {}
    bool changeCurrChoice(Dir);
    int getNumOfChoices() const;
    int getCurrChoice() const;
    Text getChoice(int) const;
};

#endif // COURSE_PROJECT_MENU
