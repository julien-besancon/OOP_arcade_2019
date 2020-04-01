/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/
#include <ncurses.h>
#include <curses.h>
#include <string>
#include "../src/Core.hpp"

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
    noecho();
    curs_set(FALSE);
    clear();
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
    static int i = 1;
    int command = getch();


    clear();
    switch (command) {
    case 65: i--;
        break;
    case 66: i++;
        break;
    }
    mvprintw(2, 2, "%d", i);
    if (i < 1)
        i = 1;
    if (i > 4)
        i = 4;
    mvprintw(4, 4, "%d", i);
    switch (i) {
    case 1:
        mvprintw(10, 25, "-->");
        break;
    case 2:
        mvprintw(15, 25, "-->");
        break;
    case 3:
        mvprintw(20, 25, "-->");
        break;
    case 4:
        mvprintw(25, 25, "-->");
        break;
    }
    return (0);
}

void display_menu()
{
    mvprintw(10, 30, "PLAY");
    mvprintw(15, 30, "NEXT GAME");
    mvprintw(20, 30, "PREVIOUS GAME");
    mvprintw(25, 30, "EXIT");
}

char ncurse::menu()
{
    display_menu();
    int i = menu_action();
    if (i != 0)
        return i;
    refresh();
}

int pause_action()
{
    static int i = 1;
    int command = getch();

    clear();
    switch (command) {
    case 65: i--;
        break;
    case 66: i++;
        break;
    }
    if (i < 1)
        i = 1;
    if (i > 5)
        i = 5;
    switch (i) {
    case 1:
        mvprintw(10, 25, "-->");
        break;
    case 2:
        mvprintw(15, 25, "-->");
        break;
    case 3:
        mvprintw(20, 25, "-->");
        break;
    case 4:
        mvprintw(25, 25, "-->");
        break;
    case 5:
        mvprintw(30, 25, "-->");
        break;
    }
    return (0);
}

void display_pause()
{
    mvprintw(10, 30, "RESUME");
    mvprintw(15, 30, "RESTART");
    mvprintw(20, 30, "BACK TO MENU");
    mvprintw(25, 30, "NEXT LIB");
    mvprintw(30, 30, "PREVIOUS LIB");
}

char ncurse::pause()
{
    display_pause();
    int i = pause_action();
    if (i != 0)
        return i;
    refresh();
}