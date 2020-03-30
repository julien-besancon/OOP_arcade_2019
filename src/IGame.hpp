/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_
#include "IGraph.hpp"

class IGame {
    public:
        virtual char game_loop(IGraph *graph) = 0;
        virtual void move(char move) = 0;
        virtual void pause() = 0;
    protected:
    private:
};

#endif /* !IGAME_HPP_ */
