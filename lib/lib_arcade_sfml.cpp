/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_sfml
*/
#include "../src/Core.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class sfml : public IGraph
{
    public:
        sfml();
        ~sfml();

        void display(int game_map[20][40]);
        input get_input(input current);
        input menu(Core &core);
        input pause();
        void display_score(int score);
        void display_game_name(std::string name);
        std::string game_over_screen();
        void end();

        sf::Sprite _spritepause;
        sf::Sprite _spritemenu;
        sf::RenderWindow _window;
        sf::Texture _texturemenu;
        sf::Texture _texturepause;
};

sfml::sfml()
{
    _window.create(sf::VideoMode(1920, 1080), "My window");

    if (!_texturemenu.loadFromFile("./lib/ressource/sfml/menu_bg.jpeg")) {
        std::cout << "ERREUR... le fichier png du MENU MOCHE n'est pas présent dans le répertoire" << std::endl;
        end();
    }

    if (!_texturepause.loadFromFile("./lib/ressource/sfml/menumoche.png")) {
        std::cout << "ERREUR... le fichier png du MENU PAUSE n'est pas présent dans le répertoire" << std::endl;
        end();
    }
    _spritepause.setTexture(_texturepause);
    _spritemenu.setTexture(_texturemenu);
}

sfml::~sfml()
{
}

void sfml::end()
{
    _window.close();
}

void sfml::display(int game_map[20][40])
{
}

void sfml::display_score(int score)
{

}

void sfml::display_game_name(std::string name)
{

}

std::string sfml::game_over_screen()
{
    return("");
}

input sfml::get_input(input current)
{
    return(current);
}

input sfml::menu(Core &core)
{
    _window.clear();
    _window.draw(_spritemenu);
    _window.display();
    return(undefinied);
}

input sfml::pause()
{
    _window.clear();
    _window.draw(_spritepause);
    _window.display();
    return(undefinied);
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}