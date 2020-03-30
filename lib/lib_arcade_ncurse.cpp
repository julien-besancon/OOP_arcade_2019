#include <iostream>
#include "../src/IGraph.hpp"

class ncurse : public IGraph
{
    void display() ;
    void get_input();
    void menu();
};

void ncurse::display() 
{
    std::cout << "NCURSE" << std::endl;
}

void ncurse::get_input() 
{
}

void ncurse::menu() 
{
}

extern "C" IGraph *create() {
    ncurse *graph = new ncurse();
    return graph;
}