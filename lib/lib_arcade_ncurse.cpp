/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/

#include "../src/Core.hpp"
#include <ncurses.h>
#include <curses.h>

class ncurse : public IGraph
{
    public:
        ncurse();
        virtual ~ncurse();

        void display();
        char get_input();
        char menu();
        char pause();
};

ncurse::ncurse()
{
}

ncurse::~ncurse()
{
}

void ncurse::display() 
{
    std::cout << "NCURSE" << std::endl;
}

char ncurse::get_input() 
{
    switch (com) { // com represente le int qui doit getch
        case KEY_UP :
        break;
        case KEY_RIGHT :
        break;
        case KEY_LEFT : 
        break;
        case KEY_DOWN :
        break;
        case 80 : // P
        break;
        case 112 : //p
        break;
    }
}

char ncurse::menu() 
{
}

char ncurse::pause() 
{
}


extern "C" IGraph *create() {
    ncurse *graph = new ncurse();
    return graph;
}