/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** main.c
*/

#include "game.hpp"

int ncurses() {
    
    size_t ymax, xmax;
    size_t ytmp, xtmp;
    int i;

    initscr();
    curs_set(0);
    getmaxyx(stdscr, ymax, xmax);
    ytmp = ymax;
    xtmp = xmax;
    game b(ymax, xmax);
    while (i != 27) {
        if (ymax != ytmp || xmax != ytmp) {
            getmaxyx(stdscr, ymax, xmax);
            ytmp = ymax;
            xtmp = xmax;
            game b(ymax, xmax);
        }
        i = getch();
        refresh();
    }
    endwin();
    return 0;
}

int main () {

    ncurses();
    return 0;
}