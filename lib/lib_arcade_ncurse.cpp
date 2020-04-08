/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <string>
#include "../src/Core.hpp"

class ncurse : public IGraph
{
    public:
        ncurse();
        virtual ~ncurse();

        void display(int game_map[20][40]);
        input get_input(input current);
        input menu(Core &core);
        input pause();
        void display_score(int score);
        std::string game_over_screen();
        void end();
        WINDOW *win;
};

ncurse::ncurse()
{
    win = initscr();
    noecho();
    curs_set(FALSE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    clear();
}

ncurse::~ncurse()
{
    endwin();
}

void ncurse::display_score(int score)
{
    mvprintw(5, 90, "SCORE : %d", score);
}

std::string ncurse::game_over_screen()
{
    char char_name[80];

    nodelay(win, false);
    clear();
    mvprintw(10, 30, "ENTER YOUR NAME : ");
    refresh();
    echo();
    getstr(char_name);
    std::string name(char_name);
    noecho();
    return (name);
}

void ncurse::display(int game_map[20][40])
{
    std::string map = "";
    static int i = 0;
    clear();
    for (int y = 0; y != 20; y++) {
        for (int x = 0; x != 40; x++) {
            switch (game_map[y][x]) {
                case 0 : map.push_back(' ');
                break;
                case 1 : map.push_back('#');
                break;
                case 2 : map.push_back('F');
                break;
                case 3 : map.push_back('O');
                break;
                case 4 : map.push_back('X');
                break;
            }
            map.push_back(' ');
        }
        map.push_back('\n');
    }
    attron(COLOR_PAIR(1));
    printw("%s", map.c_str());
    attroff(COLOR_PAIR(1));
    refresh();
}

input ncurse::get_input(input current)
{
    nodelay(win, true);
    int command = getch();

    switch (command) {
        case 65 /* KEY_UP */ : return up;
        break;
        case 67 /* KEY_RIGHT */ : return right;
        break;
        case 68/* KEY_LEFT */ : return left;
        break;
        case 66 /* KEY_DOWN */ : return down;
        break;
        case 80 : return make_pause;
        case 112 : return make_pause;
    }
    return (current);
}

void display_menu(int i, Core &core)
{
        switch (i) {
    case 1:
        mvprintw(5, 15, "-->");
        break;
    case 2:
        mvprintw(10, 15, "-->");
        break;
    case 3:
        mvprintw(15, 15, "-->");
        break;
    case 4:
        mvprintw(20, 15, "-->");
        break;
    }
    mvprintw(5, 50, "Current game lib : %s", core.game_lib_name[core.game_lib_nb].c_str());
    mvprintw(11, 50, "Available game lib : ");
    for (int i = 11, a = 0 ; a < core.game_lib_name.size() ; i += 2, a += 1)
        mvprintw(i, 71, "%s", core.game_lib_name[a].c_str());
    mvprintw(5, 20, "PLAY");
    mvprintw(10, 20, "NEXT GAME");
    mvprintw(15, 20, "PREVIOUS GAME");
    mvprintw(20, 20, "EXIT");
}

int menu_action(Core &core)
{
    static int i = 1;
    int command;
    clear();
    display_menu(i, core);
    command = getch();
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
    refresh();
    return (0);
}

input ncurse::menu(Core &core)
{
    nodelay(win, false);
    int i = menu_action(core);
    if (i != 0)
        switch (i) {
            case 1: return play;
            case 2: return next_game;
            case 3: return prev_game;
            case 4: return make_end;
        }
    return (undefinied);
}

void display_pause(int i)
{
        switch (i) {
    case 1:
        mvprintw(5, 25, "-->");
        break;
    case 2:
        mvprintw(8, 25, "-->");
        break;
    case 3:
        mvprintw(11, 25, "-->");
        break;
    case 4:
        mvprintw(14, 25, "-->");
        break;
    case 5:
        mvprintw(17, 25, "-->");
        break;
    case 6:
        mvprintw(20, 25, "-->");
        break;
    }
    mvprintw(5, 30, "RESUME");
    mvprintw(8, 30, "RESTART");
    mvprintw(11, 30, "BACK TO MENU");
    mvprintw(14, 30, "NEXT LIB");
    mvprintw(17, 30, "PREVIOUS LIB");
    mvprintw(20, 30, "EXIT");
}

int pause_action()
{
    static int i = 1;
    int command;

    clear();
    display_pause(i);
    command = getch();
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
    refresh();
    return (0);
}

input ncurse::pause()
{
    nodelay(win, false);
    int i = pause_action();
    if (i != 0)
        switch (i) {
            case 1: return play;
            case 2: return restart;
            case 3: return back_to_menu;
            case 4: return next_lib;
            case 5: return prev_lib;
            case 6: return make_end;
        }
    return (undefinied);
}

extern "C" IGraph *create() {
    ncurse *graph = new ncurse();
    return graph;
}