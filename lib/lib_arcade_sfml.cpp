/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_sfml
*/
#include "../src/Core.hpp"

class sfml : public IGraph
{
    public:
        sfml();
        virtual ~sfml();

        void init();
        void display(int game_map[20][40]);
        input get_input();
        input menu();
        input pause();
        void end();
};

sfml::sfml()
{
}

sfml::~sfml()
{
}

void sfml::init()
{
    std::cout << "init..." << std::endl;
}

void sfml::end()
{
}

void sfml::display(int game_map[20][40])
{
    std::cout << "SFML" << std::endl;
}

input sfml::get_input()
{
}

input sfml::menu()
{
    std::cout << "menu" << std::endl;
}

input sfml::pause()
{
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}