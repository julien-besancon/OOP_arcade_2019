/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_nibbler
*/
#include <iostream>
#include <unistd.h>
#include "../src/Core.hpp"

class nibbler : public IGame
{
    public:
        void pause();
        char game_loop(Core &core);
        void move(char move);
};

char nibbler::game_loop(Core &core)
{
    int i = 0;
    while (1) {
        //std::cout << core.graph_lib_nb << std::endl;
        //core.graph->display();
        core.graph->display();
        std::cout << "--> " << i++ << std::endl;
        core.next_graph();
        sleep(1);
        //return'x';
    }
}

void nibbler::pause()      // appel la fonction menu() de IGraph
{
    std::cout << "pause" << std::endl;
}

void nibbler::move(char move)
{

}

extern "C" IGame *create() {
    nibbler *game = new nibbler();
    return game;
}