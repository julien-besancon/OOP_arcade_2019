/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** IGraph
*/

#ifndef IGRAPH_HPP_
#define IGRAPH_HPP_

class IGraph {
    public:
        virtual void display() = 0;
        virtual void get_input() = 0;
        virtual void menu() = 0;
    protected:
    private:
};

#endif /* !IGRAPH_HPP_ */
