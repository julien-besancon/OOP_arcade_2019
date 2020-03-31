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

class Core;

class IGraph {
    public:
        virtual void display() = 0;
        virtual void get_input() = 0;
        virtual void menu() = 0;
    protected:
    private:
};

class IGame {
    public:
        virtual char game_loop(Core &core) = 0;
        virtual void move(char move) = 0;
        virtual void pause() = 0;
    protected:
    private:
};

class Core {
    public:
        Core(std::string);
        ~Core();

        void set_game_lib();
        void set_graph_lib();
        void next_game();
        void prev_game();
        void next_graph();
        void prev_graph();

        IGame *game;
        IGraph *graph;
        std::vector<std::string> graph_lib_name = {"./lib_arcade_ncurse.so", "./lib_arcade_sfml.so"};
        int graph_lib_nb;
        std::vector<std::string> game_lib_name = {"./lib_arcade_nibbler.so", "./lib_arcade_pacman.so"};
        int game_lib_nb = 0;
        void *_game_handle = NULL;
        void *_graph_handle = NULL;
};

#endif /* !CORE_HPP_ */