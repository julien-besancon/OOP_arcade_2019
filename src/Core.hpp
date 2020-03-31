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
        virtual ~IGraph(){};

        virtual void init() = 0;
        virtual void display() = 0;
        virtual char get_input() = 0;
        virtual char menu() = 0;
        virtual char pause() = 0;
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

        virtual char game_loop(Core &core) = 0;
        virtual void move(char move) = 0;
        virtual void pause() = 0;
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