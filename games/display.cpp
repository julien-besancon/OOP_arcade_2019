/*
** EPITECH PROJECT, 2018
** display
** File description:
** managed the display of the different element
*/

#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my.h"

void display(var_t *var)
{
    var->bird.left = 0;
    var->bird.top = 0;
    var->bird.width = 110;
    var->bird.height = 110;
    sfVector2f vecteurmove = {1, 0};

    while (sfRenderWindow_isOpen(var->window)) {
        sfSprite_move(var->spriteduck, vecteurmove);
        var->vecteurmove2.x = -100;
        var->vecteurmove2.y = rand() % 500;
        sfRenderWindow_display(var->window);
        sfRenderWindow_drawSprite(var->window, var->sprite, NULL);
        sfSprite_setTextureRect(var->spriteduck, var->bird);
        sfRenderWindow_drawSprite(var->window, var->spriteduck, NULL);
        display_duck(var);
        event(var);
    }
}