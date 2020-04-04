/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Core
*/
#include <dlfcn.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Core.hpp"

Core::Core(std::string str)
{
    int i = 0;
    if (std::find(graph_lib_name.begin(), graph_lib_name.end(), str) == graph_lib_name.end()) {
        std::cerr << "This lib doesn't exist !" << std::endl;
        exit (84);
    }
    for (; str.compare(graph_lib_name[i]) ; i++);
    graph_lib_nb = i;
    set_game_lib();
    set_graph_lib();
}

Core::~Core()
{
}

void Core::save_score(int score)
{
    std::ofstream myfile("./bonus/SCORE", std::ios::app);

    if (myfile.is_open()) {
        myfile << player_name << " : " << score << std::endl;
        myfile.close();
    }
}

void Core::set_game_lib()
{
    if (_game_handle)
        dlclose(_game_handle);
    _game_handle = dlopen(game_lib_name[game_lib_nb].c_str(), RTLD_LAZY);
    if (!_game_handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit (84);
    }
    IGame *(*create) (void);
    *(void **) (&create) = dlsym(_game_handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol" << dlsym_error << std::endl;
        dlclose(_game_handle);
        exit (84);
    }
    game = create();
}

void Core::set_graph_lib()
{
    if (_graph_handle) {
        graph->end();
        dlclose(_graph_handle);
    }
    _graph_handle = dlopen(graph_lib_name[graph_lib_nb].c_str(), RTLD_LAZY);
    if (!_graph_handle) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit (84);
    }
    IGraph *(*create) (void);
    *(void **) (&create) = dlsym(_graph_handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol" << dlsym_error << std::endl;
        dlclose(_graph_handle);
        exit (84);
    }
    graph = create();
}

void Core::next_game()
{
    if ((game_lib_nb + 1) == game_lib_name.size())
        game_lib_nb = 0;
    else
        game_lib_nb++;
    set_game_lib();
}

void Core::prev_game()
{
    if (game_lib_nb == 0)
        game_lib_nb = game_lib_name.size() - 1;
    else
        game_lib_nb--;
    set_game_lib();
}

void Core::next_graph()
{
    if ((graph_lib_nb + 1) == graph_lib_name.size())
        graph_lib_nb = 0;
    else
        graph_lib_nb++;
    set_graph_lib();
}

void Core::prev_graph()
{
    if (graph_lib_nb == 0)
        graph_lib_nb = graph_lib_name.size() - 1;
    else
        graph_lib_nb--;
    set_graph_lib();
}