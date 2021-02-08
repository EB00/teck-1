/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** end
*/
#include "my.h"

void init_back_ground_end(all_t *all)
{
    all->bg.sprite = sfSprite_create();
    if(all->e.victory == 1)
        all->bg.texture = sfTexture_createFromFile("game_over.jpg", NULL);
    else
        all->bg.texture = sfTexture_createFromFile("victory.jpg", NULL);
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfTrue);
}

void init_sound_end(all_t *all)
{
    if(all->e.victory == 1)
        all->m.music_menu = sfMusic_createFromFile("END.ogg");
    else
        all->m.music_menu = sfMusic_createFromFile("victory.ogg");
    sfMusic_setLoop(all->m.music_menu, 1);
    sfMusic_play(all->m.music_menu);
}

void init_end(all_t *all)
{
    all->mp.x = 0;
    all->mp.y = 0;
    init_back_ground_end(all);
    init_sound_end(all);
}

void display_end(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->bg.sprite, NULL);
    all->mp.x = sfMouse_getPositionRenderWindow(all->b.window).x;
    all->mp.y = sfMouse_getPositionRenderWindow(all->b.window).y;
}

void distroy_end(all_t *all)
{
//    sfMusic_destroy(all->m.music_menu);
    sfMusic_stop(all->m.music_menu);
}

void game_over(all_t *all)
{
    init_end(all);
    while (sfRenderWindow_isOpen(all->b.window)) {
        sfRenderWindow_clear(all->b.window, sfBlack);
        display_end(all);
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            if (all->e.ev.type == sfEvtMouseButtonPressed){
                distroy_end(all);
                menu(all);
            }
            if (all->e.ev.type == sfEvtClosed){
                distroy_end(all);
                sfRenderWindow_close(all->b.window);
            }
        }
        sfRenderWindow_display(all->b.window);
    }
}
