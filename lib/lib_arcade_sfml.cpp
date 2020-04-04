/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_sfml
*/
#include "../src/Core.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class sfml : public IGraph
{
    public:
        sfml();
        virtual ~sfml();

        void display(int game_map[20][40]);
        input get_input(input current);
        input menu();
        input pause();
        void display_score(int score);
        std::string game_over_screen();
        void end();

        void mesfonction(){};
    private:
        sf::Texture _texturemenu;
        sf::Sprite _spritemenu;
        sf::Texture _texturepause;
        sf::Sprite _spritepause;
        sf::RenderWindow _window;
};

sfml::sfml()
{
    sf::RenderWindow _window(sf::VideoMode(800, 600), "My games");
    if (!_texturemenu.loadFromFile("../games/ressources/menumoche.png")) {
        std::cout << "ERREUR... le fichier png du MENU MOCHE n'est pas présent dans le répertoire" << std::endl;
    }

    if (!_texturepause.loadFromFile("../games/ressources/menupause.png")) {
        std::cout << "ERREUR... le fichier png du MENU PAUSE n'est pas présent dans le répertoire" << std::endl;
    }
    _spritepause.setTexture(_texturepause);
    _spritemenu.setTexture(_texturemenu);
}

sfml::~sfml()
{
}

void sfml::end()
{
}

void sfml::display_score(int score)
{

}

std::string sfml::game_over_screen()
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
    
    _texturemenu.update(_window);
    sf::RenderTexture.display()
}

input sfml::pause()
{
    _texturepause.update(_window);
    _spritepause.
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}