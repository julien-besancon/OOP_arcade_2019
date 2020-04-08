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
        virtual void display_score(int score) = 0;
        virtual std::string game_over_screen() = 0;
        virtual input get_input(input current) = 0;
        virtual input menu(Core &core) = 0;
        virtual input pause() = 0;
    protected:
    private:
};

enum state {
    GAME,
    PAUSE,
    MENU,
    GAME_OVER,
};

class IGame {
    public:
        virtual ~IGame(){};

        virtual input game_loop(Core &core) = 0;
        virtual input move(input move) = 0;
    protected:
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
        virtual void save_score(int score) = 0;
};

class Core : public ICore {
    public:
        Core(std::string str);
        ~Core();

        void set_game_lib();
        void set_graph_lib();
        void next_game();
        void prev_game();
        void next_graph();
        void prev_graph();
        void save_score(int score);

        IGame *game = NULL;
        IGraph *graph = NULL;
        std::string player_name;
        std::vector<std::string> graph_lib_name = {"./lib_arcade_ncurse.so", "./lib_arcade_sfml.so"/* , "./lib_arcade_sdl.so" */};
        int graph_lib_nb;
        std::vector<std::string> game_lib_name = {"./lib_arcade_nibbler.so", "./lib_arcade_pacman.so"};
        int game_lib_nb = 0;
        void *_game_handle = NULL;
        void *_graph_handle = NULL;
};

#endif /* !CORE_HPP_ */