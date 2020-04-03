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
        input game_loop(Core &core) override;
        void move(input move) override;
        state game_state = MENU;
};

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

input Nibbler::game_loop(Core &core)
{
    int i = 0;
    input in = undefinied;

    while (1) {
        switch (game_state) {
        case GAME:
            in = core.graph->get_input();
            if (in == make_pause)
                game_state = PAUSE;
            move(in);
            //core.graph->display();
            break;

        case PAUSE:
            in = core.graph->pause();
            if (in == back_to_menu)
                game_state = MENU;
            break;

        case MENU:
            in = core.graph->menu();
            break;
        }
        if (in == play) {
            game_state = GAME;
            in = undefinied;
        }
        if (in == next_lib) {
            core.next_graph();
            in = undefinied;
        }
        if (in == prev_lib) {
            core.prev_graph();
            in = undefinied;
        }


        //std::cout << "--> " << i++ << std::endl;
        //core.next_graph();


        if (in == restart) {
            game_state = GAME;
            return in;
        }
        if (in == next_game || in == prev_game || in == make_end)
            return in;
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

void Nibbler::move(input move)
{
    switch (move) {
    case up:
        /* code */
        break;
    case down:
        /* code */
        break;
    case left:
        /* code */
        break;
    case right:
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