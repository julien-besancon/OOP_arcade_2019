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

        void init();
        void display();
        char get_input();
        char menu();
        char pause();
        void end();
};

extern "C" IGraph *create() {
    ncurse *graph = new ncurse();
    return graph;
}

ncurse::ncurse()
{
}

ncurse::~ncurse()
{
}

void ncurse::init()
{
}

void ncurse::end()
{
}

void ncurse::display() 
{
    std::cout << "NCURSE" << std::endl;
}

char ncurse::get_input() 
{
    int com;
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
int menu_action()
{
    //getch();





    return (0);
}

void display_menu()
{

}

char ncurse::menu() 
{
    int i = menu_action();
    if (i != 0)
        return i;
    display_menu();
}

int pause_action()
{
    //getch();






    return (0);
}
void display_pause()
{

}

char ncurse::pause() 
{
    int i = pause_action();
    if (i != 0)
        return i;
    display_pause();
}