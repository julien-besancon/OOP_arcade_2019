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
        //state game_state = MENU;
};

Nibbler::Nibbler()
{
}

Nibbler::~Nibbler()
{
}

char Nibbler::game_loop(Core &core)
{
    int i = 0;
    char input = 'u';
    while (1) {
        input = core.graph->get_input();
        move(input);





        core.graph->display();
        std::cout << "--> " << i++ << std::endl;
        core.next_graph();
/*         if (game_state == GAME)
            core.graph->display();
        else if (game_state == PAUSE)
            pause();
        else if (game_state == MENU)
            input = core.graph->menu();
        if (input == 'r' || input == 'n' || input == 'p')
            return input; */
        sleep(1);
    }
}

void Nibbler::pause()      // appel la fonction menu() de IGraph
{
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
}

extern "C" IGame *create() {
    Nibbler *game = new Nibbler();
    return game;
}