/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_nibbler
*/
#include <iostream>
#include <unistd.h>
#include "../src/Core.hpp"

class Nibbler : public IGame
{
    public:
        Nibbler();
        virtual ~Nibbler();

        void pause() override;
        char game_loop(Core &core) override;
        void move(char move) override;
        state game_state = MENU;
};

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

enum input {
    undefinied = 'u',
    play = 'g',
    make_pause = 'p',
    restart = 'r',
    back_to_menu = 'm',
    next_lib = '+',
    prev_lib = '-',
    next_game = 'n',
    prev_game = 'b',
};

char Nibbler::game_loop(Core &core)
{
    int i = 0;
    char input = 'u';
    while (1) {
        switch (game_state) {
        case GAME:
            input = core.graph->get_input();
            if (input == 'p')
                game_state = PAUSE;
            move(input);
            core.graph->display();
            break;

        case PAUSE:
            input = core.graph->pause();
            if (input == 'm')
                game_state = MENU;
            break;

        case MENU:
            input = core.graph->menu();
            break;
        }
        if (input == 'g') {
            game_state = GAME;
            input = 'u';
        }
        if (input == '-') {
            core.next_graph();
            input = 'u';
        }
        if (input == '+') {
            core.prev_graph();
            input = 'u';
        }


        //std::cout << "--> " << i++ << std::endl;
        //core.next_graph();


        if (input == 'r' || input == 'n' || input == 'b' || input == 'x')
            return input;
        //sleep(1);
    }
}

void Nibbler::pause()      // appel la fonction menu() de IGraph
{
}

void is_eaten()
{
    //if()
    //    eat();
}

void Nibbler::move(char move)
{
    switch (move) {
    case 'u':
        /* code */
        break;
    case 'd':
        /* code */
        break;
    case 'l':
        /* code */
        break;
    case 'r':
        /* code */
        break;
    default:
        /* code */
        break;
    }
    is_eaten();
}

extern "C" IGame *create() {
    Nibbler *game = new Nibbler();
    return game;
}