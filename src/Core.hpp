/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <vector>
#include <iostream>
#include "IGame.hpp"
#include "IGraph.hpp"

class Core {
    public:
        Core();
        ~Core();

        void next_game();
        void prev_game();
        void next_graph();
        void prev_graph();

        IGame *game;
        IGraph *graph;
        std::vector<std::string> graph_lib_name = {"./lib_arcade_ncurse.so", "./lib_arcade_sfml.so"};
        int graph_lib_nb;
        std::vector<std::string> game_lib_name = {"./lib_arcade_nibbler.so", "./lib_arcade_pacman.so"};
        int game_lib_nb;
};

#endif /* !CORE_HPP_ */