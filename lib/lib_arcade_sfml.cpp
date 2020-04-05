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
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>  
#include <sstream>

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
        std::string game_over_screen();
        input menu_event_loop();
        input pause_event_loop();
        void display_menu();
        void display_pause();
        std::string event_game_over();
        void end();
        
        sf::Event _event;
        sf::Sprite _spritepause;
        sf::Sprite _spritemenu;
        sf::Sprite _spriteover;
        sf::Sprite _spritearrow;
        sf::RenderWindow _window;
        sf::Texture _texture_menu;
        sf::Texture _texture_over;
        sf::Texture _texture_pause;
        sf::Texture _texture_arrow;
        sf::Texture _texture_wall;
        sf::Texture _texture_floor;
        sf::Texture _texture_apple;
        sf::Texture _texture_snake_body;
        sf::Texture _texture_snake_head;
        sf::Sprite _sprite_list[20][40];
        sf::Font _score_font;
        sf::Text _score_text;
        sf::Text _gameover_text;
        sf::Text _currentlib_text;
};

sfml::sfml()
{
    _window.create(sf::VideoMode(1920, 1080), "My window");

    _score_font.loadFromFile("./lib/ressource/sfml/BEBAS.ttf");
    _texture_menu.loadFromFile("./lib/ressource/sfml/menu_bg1080p.png");
    _texture_over.loadFromFile("./lib/ressource/sfml/over.png");
    _texture_pause.loadFromFile("./lib/ressource/sfml/menupause.png");
    _texture_arrow.loadFromFile("./lib/ressource/sfml/arrow.png");
    _texture_wall.loadFromFile("./lib/ressource/sfml/wall.png");
    _texture_floor.loadFromFile("./lib/ressource/sfml/floor.png");
    _texture_apple.loadFromFile("./lib/ressource/sfml/apple.png");
    _texture_snake_body.loadFromFile("./lib/ressource/sfml/snake_body.png");
    _texture_snake_head.loadFromFile("./lib/ressource/sfml/snake_head.png");
    _score_text.setFont(_score_font);
    _currentlib_text.setFont(_score_font);
    _gameover_text.setFont(_score_font);
    _spritepause.setTexture(_texture_pause);
    _spritemenu.setTexture(_texture_menu);
    _spriteover.setTexture(_texture_over);
    _spritearrow.setTexture(_texture_arrow);
    _spritearrow.setPosition(200, 200);
    _spritearrow.setScale(0.05, 0.05);
    _gameover_text.setPosition(1000, 500);
    _score_text.setCharacterSize(50);
    _score_text.setPosition(1000,0);
    for (int y = 0, a = 0; y != 20; y++)
        for (int x = 0; x != 40; x++, a++)
            _sprite_list[y][x].setPosition((x*40)+140, (y*40)+160);
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
    _window.clear();
    for (int y = 0, a = 0; y != 20; y++)
        for (int x = 0; x != 40; x++, a++)
            switch (game_map[y][x]) {
                case 0 : _sprite_list[y][x].setTexture(_texture_floor);
                break;
                case 1 : _sprite_list[y][x].setTexture(_texture_wall);
                break;
                case 2 : _sprite_list[y][x].setTexture(_texture_apple);
                break;
                case 3 : _sprite_list[y][x].setTexture(_texture_snake_head);
                break;
                case 4 : _sprite_list[y][x].setTexture(_texture_snake_body);
                break;
            }
    for (int y = 0, a = 0; y != 20; y++)
        for (int x = 0; x != 40; x++, a++)
            _window.draw(_sprite_list[y][x]);
}

void sfml::display_score(int score)
{
    
    _score_text.setString("score :" + std::to_string(score));
    _window.draw(_score_text);
    _window.display();
}

std::string sfml::event_game_over()
{
    static std::string str = "";
    while (_window.pollEvent(_event)) {

    _window.draw(_gameover_text);
        if (_event.type == sf::Event::Closed) {
            end();
            exit(0);
        }
        if (_event.type == _event.TextEntered)
            if (_event.text.unicode < 127 && _event.text.unicode > 32)
                str += static_cast<char>(_event.text.unicode);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space)
            str += " ";
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Return)
            return str;
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::BackSpace)
            str.pop_back();
    }
    _gameover_text.setString(str);
    _window.draw(_spriteover);
    _window.draw(_gameover_text);
    _window.display();
    return "";
}

std::string sfml::game_over_screen()
{
    _window.clear();
    return(event_game_over());
}

input sfml::get_input(input current)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return make_end;
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Up)
            return up;
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Down) 
            return down;
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Right) 
            return right;
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Left) 
            return left;
        if (_event.type == sf::Event::KeyPressed && (_event.key.code == sf::Keyboard::P
        || _event.key.code == sf::Keyboard::Escape))
            return make_pause;
        }
    return current;
}

input sfml::menu_event_loop()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            return make_end;
        }
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Up) {
                if (_spritearrow.getPosition().y > 200)
                    _spritearrow.move(0, -200);
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Down) {
                if (_spritearrow.getPosition().y < 800)
                    _spritearrow.move(0, 200);
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Return) {
                if (_spritearrow.getPosition().y == 200)
                    return play;
                if (_spritearrow.getPosition().y == 400)
                    return next_lib;
                if (_spritearrow.getPosition().y == 600)
                    return prev_lib;
                if (_spritearrow.getPosition().y == 800)
                    return make_end;
            }
    }
    return undefinied;
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
    input res = menu_event_loop();
    display_menu();
    return(res);
}

input sfml::pause_event_loop()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            return make_end;
        }
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Up) {
                if (_spritearrow.getPosition().y > 200)
                    _spritearrow.move(0, -100);
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Down) {
                if (_spritearrow.getPosition().y < 700)
                    _spritearrow.move(0, 100);
            }

        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Return) {
                if (_spritearrow.getPosition().y == 200)
                    return play;
                if (_spritearrow.getPosition().y == 300)
                    return restart;
                if (_spritearrow.getPosition().y == 400)
                    return back_to_menu;
                if (_spritearrow.getPosition().y == 500)
                    return next_lib;
                if (_spritearrow.getPosition().y == 600)
                    return prev_lib;
                if (_spritearrow.getPosition().y == 700)
                    return make_end;
            }
    }
    return undefinied;
}

void sfml::display_pause()
{
    _window.clear();

    _window.draw(_spritepause);
    _window.draw(_spritearrow);

    _window.display();
}

input sfml::pause()
{
    input res = pause_event_loop();
    display_pause();
    return(res);
}

extern "C" IGraph *create() {
    sfml *graph = new sfml();
    return graph;
}