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

enum input {
    undefinied,
    play,
    make_pause,
    restart,
    back_to_menu,
    next_lib,
    prev_lib,
    next_game,
    prev_game,
    up,
    down,
    left,
    right,
    make_end,
    game_over,
};

class IGraph {
    public:
        virtual ~IGraph(){};

        virtual void display(int game_map[20][40]) = 0;
        virtual input get_input(input current) = 0;
        virtual input menu() = 0;
        virtual input pause() = 0;
        virtual void end() = 0;
    protected:
    private:
};

enum state {
    GAME,
    PAUSE,
    MENU
};

class IGame {
    public:
        virtual ~IGame(){};

        virtual input game_loop(Core &core) = 0;
        virtual input move(input move) = 0;
    protected:
        state game_state;
    private:
};

class ICore {
    public:
        virtual ~ICore(){};

        virtual void set_game_lib()= 0;
        virtual void set_graph_lib()= 0;
        virtual void next_game() = 0;
        virtual void prev_game()= 0;
        virtual void next_graph()= 0;
        virtual void prev_graph()= 0;
};

class Core : public ICore {
    public:
        Core(std::string str);
        ~Core();

        void set_game_lib() override;
        void set_graph_lib() override;
        void next_game() override;
        void prev_game() override;
        void next_graph() override;
        void prev_graph() override;

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