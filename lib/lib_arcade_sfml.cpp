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
        void display();
        char get_input();
        char menu();
        char pause();
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
}

void sfml::end()
{
}

void sfml::display() 
{
    std::cout << "SFML" << std::endl;
}

char sfml::get_input() 
{
}

char sfml::menu() 
{
}

char sfml::pause() 
{
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}