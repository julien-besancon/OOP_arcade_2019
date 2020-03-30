#include <iostream>
#include "../src/IGraph.hpp"

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