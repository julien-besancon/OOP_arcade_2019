/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/

#include "../src/Core.hpp"
#include <ncurses.h>
#include <curses.h>
#include <string>

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
    initscr();
}

void ncurse::end()
{
    endwin();
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
    int i = 1;
    int command = 4;//getch();

    switch (command) {
    case KEY_UP: i++;
        break;
    case KEY_DOWN: i--;
        break; 
    }
    if (i < 1) 
        i = 1;
    if (i > 4)
        i = 4;
    switch (i) {
    case 1:
        mvprintw(20, 25, "-->");
        break;
    case 2:
        mvprintw(40, 25, "-->");
        break;
    case 3:
        mvprintw(60, 25, "-->");
        break;
    case 4:
        mvprintw(80, 25, "-->");
        break;
    }
    return (i);
}

void display_menu()
{
    mvprintw(20, 30, "RESUME");
    mvprintw(40, 30, "NEXT GAME");
    mvprintw(60, 30, "PREVIOUS GAME");
    mvprintw(80, 30, "EXIT");
    refresh();
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
    int i = 1;
    int command = 1;//getch();

    switch (command) {
    case KEY_UP: i++;
        break;
    case KEY_DOWN: i--;
        break; 
    }
    if (i < 1) 
        i = 1;
    if (i > 5)
        i = 5;
    switch (i) {
    case 1:
        mvprintw(20, 25, "-->");
        break;
    case 2:
        mvprintw(40, 25, "-->");
        break;
    case 3:
        mvprintw(60, 25, "-->");
        break;
    case 4:
        mvprintw(80, 25, "-->");
        break;
    case 5:
        mvprintw(100, 25, "-->");
        break;
    }
    return (i);
}
void display_pause()
{
    mvprintw(20, 30, "RESUME");
    mvprintw(40, 30, "RESTART");
    mvprintw(60, 30, "BACK TO MENU");
    mvprintw(80, 30, "NEXT LIB");
    mvprintw(100, 30, "PREVIOUS LIB");
    refresh();
}

char ncurse::pause() 
{
    int i = pause_action();
    if (i != 0)
        return i;
    display_pause();
}