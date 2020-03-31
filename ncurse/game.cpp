/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** game.cpp
*/

#include "game.hpp"

game::game(size_t ymax, size_t xmax) {
    _ymax = ymax;
    _xmax = xmax;
    _arr = (int **) std::malloc(_ymax * sizeof (int*));
    for (int i = 0; i < _ymax; i++)
        _arr[i] = (int *) std::malloc(_xmax * sizeof(int));
    for (int y = 0; y !=_ymax; y++) {
        for (int x = 0; x != _xmax; x++)
            _arr[y][x] = 0;
    }
}

game::~game(){    
}
