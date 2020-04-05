/*
** EPITECH PROJECT, 2019
** OOP_arcade_2019
** File description:
** lib_arcade_sdl.cpp
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/Core.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <iostream>

class sdl : public IGraph {
    public :
        sdl();
        virtual ~sdl();

        // void display(int game_map[20][40]);
        // input get_input(input current);
        // input menu(Core &core);
        // input pause();
        // void display_score(int score);
        // std::string game_over_screen();
        // void end();
        void error(std::string, SDL_Window *_win, SDL_Renderer *_rend);
        SDL_Texture *create_free_surface(SDL_Window *_win, SDL_Renderer *_rend, std::string path_img);
        SDL_Texture *load_image( std::string filename, SDL_Renderer *_rend, SDL_Window *_win);
    private : 
        SDL_Window *_win = NULL;
        SDL_Renderer *_rend = NULL;
        SDL_Surface *exit_button = NULL;
        SDL_Surface *menu_button = NULL;
        SDL_Surface *next_game_button = NULL;
        SDL_Surface *play_button = NULL;
        SDL_Surface *previous_game_button = NULL;
        SDL_Surface *restart_button = NULL;
        SDL_Surface *resume_button = NULL;
        SDL_Texture *_texture = NULL;
        SDL_Rect _rect;
        SDL_DisplayMode dm;
};

void clean_ressource(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t, std::string buffer) {

    SDL_Log(buffer.c_str(), SDL_GetError());
    if (t != NULL)
        SDL_DestroyTexture(t);
    if (r != NULL)
        SDL_DestroyRenderer(r);
    if (w != NULL)
        SDL_DestroyWindow(w);
    SDL_Quit();
    exit;
}

sdl::sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        clean_ressource(NULL, NULL, NULL, "Can't load SDL\n");
    SDL_GetCurrentDisplayMode(0, &dm);
    _win = SDL_CreateWindow("ARCADE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dm.w, dm.h, 0);
    if (_win == NULL)
        clean_ressource(NULL, NULL, NULL, "Can't load window\n");
    _rend = SDL_CreateRenderer(_win, -1, SDL_RENDERER_SOFTWARE);
    if (_rend == NULL) {
        clean_ressource(_win, NULL, NULL, "Can't load Render\n");
    }
    
    _texture = create_free_surface(_win, _rend, "../bonus/menu/black_screen.bmp");
    _texture = create_free_surface(_win, _rend, "../bonus/menu/play.bmp");
    _texture = create_free_surface(_win, _rend, "../bonus/menu/next_game.bmp");
    _texture = create_free_surface(_win, _rend, "../bonus/menu/previous_game.bmp");
    _texture = create_free_surface(_win, _rend, "../bonus/menu/exit.bmp");
    

    if (SDL_QueryTexture(_texture, NULL, NULL, &_rect.w, &_rect.h) != 0) {
        clean_ressource(_win, _rend, _texture, "Can't load page\n");
    }
    _rect.x = (dm.w - _rect.w) /2;
    _rect.y = (dm.h - _rect.h) /2; // Pour centrer les images en fonction de la taille de l'écran héhé

    if (SDL_RenderCopy(_rend, _texture, NULL, &_rect) != 0)
        clean_ressource(_win, _rend, _texture, "Can't display window\n");
    SDL_RenderPresent(_rend);
//    SDL_Surface *background = IMG_Load("../bonus/menu_sdl/black_screen.png");
}
sdl::~sdl()
{
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_rend);
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

void error(std::string buffer, SDL_Window *_win, SDL_Renderer *_rend) {
    SDL_DestroyRenderer(_rend);
    SDL_DestroyWindow(_win);
    SDL_Log(buffer.c_str(), SDL_GetError());
    exit;
}


SDL_Texture *create_free_surface(SDL_Window *_win, SDL_Renderer *_rend, std::string path_img) {

    SDL_Surface *tmp_img = SDL_LoadBMP(path_img.c_str());
    SDL_Texture *tmp = SDL_CreateTextureFromSurface(_rend, tmp_img);
    SDL_FreeSurface(tmp_img);
    if (tmp == NULL)
        clean_ressource(_win, _rend, NULL, "Can't load texture\n");
    return (tmp);
}
