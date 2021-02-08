/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** help
*/
#include "my.h"

void init_back_ground_help(all_t *all)
{
    all->bg.sprite = sfSprite_create();
    all->bg.texture = sfTexture_createFromFile("help.jpg", NULL);
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfTrue);
}

void init_sound_help(all_t *all)
{
    all->m.music_menu = sfMusic_createFromFile("HELP.ogg");
    sfMusic_setLoop(all->m.music_menu, 1);
    sfMusic_play(all->m.music_menu);
}

void init_all_help(all_t *all)
{
    all->mp.x = 0;
    all->mp.y = 0;
    init_back_ground_help(all);
    init_sound_help(all);
}

void display_help(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->bg.sprite, NULL);
    all->mp.x = sfMouse_getPositionRenderWindow(all->b.window).x;
    all->mp.y = sfMouse_getPositionRenderWindow(all->b.window).y;
}

void distroy_help(all_t *all)
{
//    sfSprite_destroy(all->bg.sprite);
//    sfTexture_destroy(all->bg.texture);
    sfMusic_destroy(all->m.music_menu);
    }

void help(all_t *all)
{
    init_all_help(all);
    while(sfRenderWindow_isOpen(all->b.window)){
         sfRenderWindow_clear(all->b.window, sfBlack);
        display_help(all);
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            if (all->e.ev.type == sfEvtMouseButtonPressed){
                distroy_help(all);
                    menu(all);
            }
            if (all->e.ev.type == sfEvtClosed){
                sfRenderWindow_close(all->b.window);
            }
        }
        sfRenderWindow_display(all->b.window);
    }
}
