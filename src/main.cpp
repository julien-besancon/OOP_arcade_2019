/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** main
*/
#include <dlfcn.h>
#include <stdio.h>
#include "Core.hpp"

void launch_game(Core &core)
{
    input c = core.game->game_loop(core);
    if (c == restart)
        launch_game(core);
    if (c == next_game) {
        core.next_game();
        launch_game(core);
    }
    if (c == prev_game) {
        core.prev_game();
        launch_game(core);
    }
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Incorrect number of arguments !" << std::endl
        << "Usage : ./arcade [Path to Dynamic library]" << std::endl;
        return (84);
    }
    Core core(av[1]);

    core.graph->init();
    launch_game(core);
    core.graph->end();
    dlclose(core._game_handle);
    dlclose(core._graph_handle);
}