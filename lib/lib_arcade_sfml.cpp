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
        
        void display();
        char get_input();
        char menu();
        char pause();
};

sfml::sfml()
{
}

sfml::~sfml()
{
    std::cout << "FIN sfml" << std::endl;
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