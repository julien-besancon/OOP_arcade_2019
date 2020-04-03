/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of the my_hunter project
*/

#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "ressources/my.h"

void destroys(var_t *var)
{
    sfSprite_destroy(var->sprite);
    sfTexture_destroy(var->texture);
    sfSprite_destroy(var->spriteduck);
    sfTexture_destroy(var->textureforduck);
    sfMusic_destroy(var->music);
    sfRenderWindow_destroy(var->window);
}

void *create_my_window(var_t *var)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    sfRenderWindow_create(video_mode, "My Hunter",
                          sfDefaultStyle, NULL);
}

void event(var_t *var)
{
    int posx;
    int posy;

    while (sfRenderWindow_pollEvent(var->window, &var->event)) {
        if (var->event.type == sfEvtMouseButtonPressed) { 
            var->mouse = sfMouse_getPositionRenderWindow(var->window);
            posx = sfSprite_getPosition(var->spriteduck).x;
            posy = sfSprite_getPosition(var->spriteduck).y;
            if (var->mouse.x >= posx && var->mouse.x <= posx + 110 &&
                var->mouse.y >= posy && var->mouse.y <= posy + 110)
                sfSprite_setPosition(var->spriteduck,var->vecteurmove2);
        }
        if (var->event.type == sfEvtClosed
            || var->event.key.code == sfKeyEscape)
            sfRenderWindow_close(var->window);
    }
}

int do_hunter(var_t *var)
{
    sfVector2f vecteurmove = {1, 0};
    sfVideoMode video_mode;
    var->x = 0;
    var->y= 0;
    srand(time(NULL));
    var->window = create_my_window(var);
    var->texture = sfTexture_createFromFile("src/view.jpg", NULL);
    var->textureforduck = sfTexture_createFromFile("src/coincoin.jpg", NULL);
    var->sprite = sfSprite_create();
    sfSprite_setTexture(var->sprite, var->texture, sfTrue);
    var->spriteduck = sfSprite_create();
    sfSprite_setTexture(var->spriteduck, var->textureforduck, sfTrue);
    var->music = sfMusic_createFromFile("src/halotheme.ogg");
    sfMusic_play(var->music);
    var->clock = sfClock_create();
    display(var);
    destroys(var);
    return (0);
}

int main(int ac, char **av, char **env)
{
    var_t var;

    if (env [0] == NULL)
        return (84);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            my_putstr("Merci de vouloir jouer à mon premier jeu,"
                      "appuyez sur echap pour quitter");
        return (0);
    } else
        if (ac == 1)
            do_hunter(&var);
    return (0);
}
