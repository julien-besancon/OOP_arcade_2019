/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** game.hpp
*/


#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>
#include <list>
#include <regex>
#include <iostream>
#include <string>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>

class game
{
public:
    game(size_t ymax, size_t xmax);
    ~game();
    
private:
    unsigned int _ymax;
    unsigned int _xmax;
    int command;
    int **_arr;
};

#endif