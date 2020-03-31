/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_ncurse
*/
#include "../src/Core.hpp"

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