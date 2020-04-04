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
#include <SFML/System.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/>

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
        input event_loop();
        void move_arrow();
        void display_menu();
        void display_pause();
        void end();
        
        sf::Event _event;
        sf::Sprite _spritepause;
        sf::Sprite _spritemenu;
        sf::Sprite _spritearrow;
        sf::RenderWindow _window;
        sf::Texture _texturemenu;
        sf::Texture _texturepause;
        sf::Texture _texturearrow;
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

    if (!_texturearrow.loadFromFile("./lib/ressource/sfml/arrow.png")) {
        std::cout << "ERREUR... le fichier png du MENU arrow n'est pas présent dans le répertoire" << std::endl;
        end();
    }
    _spritepause.setTexture(_texturepause);
    _spritemenu.setTexture(_texturemenu);
    _spritearrow.setTexture(_texturearrow);
}

sfml::~sfml()
{
}

void sfml::end()
{
    _window.close();
}

void sfml::move_arrow()
{
    sf::Vector2f position = _spritearrow.getPosition(); // = (15, 55)
    if (sf::Sprite::setPosition(_spritearrow, (sfVector2f){100, 0});
    
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

input sfml::event_loop()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || _event.key.code == sf::Keyboard::Escape)
            end();
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Up) {
                if ()
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Down) {
                if ()
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Return) {
                if ()
            }
    }
}

void sfml::display_menu()
{
    _window.clear();

    _window.draw(_spritemenu);
    _window.draw(_spritearrow);

    _window.display();
}

input sfml::menu(Core &core)
{
    event_loop();
    display_menu();
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