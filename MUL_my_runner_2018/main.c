//-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

#include "include.h"

void create_window(all_t *all)
{
    sfUint32 parm = sfResize | sfClose;
    all->b.mode = (sfVideoMode)
        {.width = 1600, .height = 871, .bitsPerPixel = 32};
    all->b.window = sfRenderWindow_create(all->b.mode, "MY_RUNNER", parm, NULL);
    sfRenderWindow_setFramerateLimit(all->b.window, 100);
}

void init_all(all_t *all)
{
    create_window(all);
    init(all);
    init_player(all);
    init_mob(all);
    init_score(all);
    init_life(all);
    init_sound(all);
}

void draw(all_t *all)
{
    sfRenderWindow_clear(all->b.window, sfBlack);
    sprite_position(all);
    mv_back(all);
    player(all);
    gravity1(all);
    score(all);
    fall(all);
    mob(all);
    boom(all);
    life(all);
}

int game(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));

    init_all(all);
    while (sfRenderWindow_isOpen(all->b.window)) {
        draw(all);
        if (victory(all, ac, av) == 1)
            return (0);
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            if (all->e.ev.type == sfEvtMouseButtonPressed){
            }
            if(all->e.ev.type == sfEvtKeyPressed &&
               all->e.ev.key.code == (sfKeySpace))
                jump(all);
            if (all->e.ev.type == sfEvtClosed){
                distroy(all);
                sfRenderWindow_close(all->b.window);
            }
        }
        sfRenderWindow_display(all->b.window);
    }
    return(0);
}

int main(int ac, char **av)
{
    game(ac, av);
}
