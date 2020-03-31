/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/
#include "../src/Core.hpp"

class ncurse : public IGraph
{
    public:
        ncurse();
        virtual ~ncurse();

        void display();
        char get_input();
        char menu();
};

ncurse::ncurse()
{
}

ncurse::~ncurse()
{
}

void ncurse::display() 
{
    std::cout << "NCURSE" << std::endl;
}

char ncurse::get_input() 
{
}

char ncurse::menu() 
{
}

extern "C" IGraph *create() {
    ncurse *graph = new ncurse();
    return graph;
}