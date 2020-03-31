/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_sfml
*/
#include "../src/Core.hpp"

class sfml : public IGraph
{
    void display();
    void get_input();
    void menu();
};

void sfml::display() 
{
    std::cout << "SFML" << std::endl;
}

void sfml::get_input() 
{
}

void sfml::menu() 
{
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}