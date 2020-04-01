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
    int command = getch();

    switch (command) {
        case KEY_UP :
        break;
        case KEY_RIGHT :
        break;
        case KEY_LEFT :
        break;
        case KEY_DOWN :
        break;
        case 80 : return 'p';
        case 112 : return 'p';
    }
}

int menu_action()
{
    static int i = 1;
    int command = getch();

    clear();
    switch (command) {
    case 65 : i--;
        break;
    case 66 : i++;
        break;
    case 10 : return (i);
    }
    if (i < 1)
        i = 1;
    if (i > 4)
        i = 4;
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
        switch (i) {
            case 1: return 'g';
            case 2: return 'n';
            case 3: return 'b';
            case 4: return 'x';
        }
        return i;
    refresh();
}

int pause_action()
{
    static int i = 1;
    int command = getch();

    clear();
    switch (command) {
    case 65 : i--;
        break;
    case 66 : i++;
        break;
    case 10 : return (i);
    }
    if (i < 1)
        i = 1;
    if (i > 6)
        i = 6;
    switch (i) {
    case 1:
        mvprintw(5, 25, "-->");
        break;
    case 2:
        mvprintw(10, 25, "-->");
        break;
    case 3:
        mvprintw(15, 25, "-->");
        break;
    case 4:
        mvprintw(20, 25, "-->");
        break;
    case 5:
        mvprintw(25, 25, "-->");
        break;
    case 6:
        mvprintw(30, 25, "-->");
        break;
    }
    return (0);
}

void display_pause()
{
    mvprintw(5, 30, "RESUME");
    mvprintw(10, 30, "RESTART");
    mvprintw(15, 30, "BACK TO MENU");
    mvprintw(20, 30, "NEXT LIB");
    mvprintw(25, 30, "PREVIOUS LIB");
    mvprintw(30, 30, "EXIT");
}

char ncurse::pause()
{
    display_pause();
    int i = pause_action();
    if (i != 0)
        switch (i) {
            case 1: return 'g';
            case 2: return 'r';
            case 3: return 'm';
            case 4: return '+';
            case 5: return '-';
            case 6: return 'x';
        }
    refresh();
}