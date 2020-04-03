/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_sfml
*/
#include "../src/Core.hpp"
//#include <SFML/Graphics.hpp>

/* #include <SFML
sfml-window-s.lib
sfml-system-s.lib */
//#include <sfml-graphics-s.lib>

class sfml : public IGraph
{
    public:
        sfml();
        virtual ~sfml();

        void display(int game_map[20][40]);
        input get_input(input current);
        input menu();
        input pause();
        void end();

        void mesfonction(){};

        sf::Texture texturemenu;
        sf::Sprite spritemenu;
        sf::Texture texturepause;
        sf::Sprite spritepause;
        sf::RenderWindow window;
};

sfml::sfml()
{
    if (!texturemenu.loadFromFile("../games/ressources/menumoche.png")) {
        std::cout << "ERREUR... le fichier png du MENU MOCHE n'est pas présent dans le répertoire" << std::endl;
    }

    if (!texturepause.loadFromFile("../games/ressources/menupause.png")) {
        std::cout << "ERREUR... le fichier png du MENU PAUSE n'est pas présent dans le répertoire" << std::endl;
    }
    spritepause.setTexture(texturepause);
    spritemenu.setTexture(texturemenu);
}

sfml::~sfml()
{
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

    texturemenu.update(window);
}

input sfml::pause()
{
    texturepause.update(window);
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}