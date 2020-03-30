#include <iostream>
#include "../src/IGraph.hpp"
#include "../src/IGame.hpp"
#include <unistd.h>

class nibbler : public IGame
{
    public:
        void pause();
        char game_loop(IGraph *graph);
        void move(char move);
};

char nibbler::game_loop(IGraph *graph)
{
    while (1) {
        graph->get_input();
        move('s');




        graph->display();
        sleep(1);
    }
}

void nibbler::pause()      // appel la fonction menu() de IGraph
{
    std::cout << "pause" << std::endl;
}

void nibbler::move(char move)
{

}

extern "C" IGame *create() {
    nibbler *game = new nibbler();
    return game;
}