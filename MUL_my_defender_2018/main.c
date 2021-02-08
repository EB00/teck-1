/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main.c
*/

#include "my.h"

void create_window(all_t *all)
{
    sfUint32 parm = sfResize | sfClose;

    all->b.mode = (sfVideoMode)
        {.width = 1920, .height = 1200, .bitsPerPixel = 32};
    all->b.window = sfRenderWindow_create(all->b.mode, "MY_DEFENDER", parm, NULL);
    sfRenderWindow_setFramerateLimit(all->b.window, 100);
}

void init_back_ground(all_t *all)
{
    all->bg.sprite = sfSprite_create();
    all->bg.texture = sfTexture_createFromFile("menu.jpg", NULL);
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfTrue);
}

void init_sound(all_t *all)
{
    all->m.music_menu = sfMusic_createFromFile("menu.ogg");
//    all->m.music_click_button = sfMusic_createFromFile("JUMP.ogg");
//    all->m.music_button = sfMusic_cre
    sfMusic_setLoop(all->m.music_menu, 1);
    sfMusic_play(all->m.music_menu);
}

void init_all(all_t *all)
{
    all->mp.x = 0;
    all->mp.y = 0;
//    create_window(all);
    init_back_ground(all);
    init_button_menu(all);
    init_sound(all);
}

void display(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->bg.sprite, NULL);
    display_button_menu(all);
    all->mp.x = sfMouse_getPositionRenderWindow(all->b.window).x;
    all->mp.y = sfMouse_getPositionRenderWindow(all->b.window).y;
}

void distroy_menu(all_t *all)
{
//    sfSprite_destroy(all->bm.sprite);
//    sfSprite_destroy(all->bm.sprite1);
//    sfSprite_destroy(all->bg.sprite);
//    sfTexture_destroy(all->bm.texture);
//    sfTexture_destroy(all->bm.texture1);
//    sfTexture_destroy(all->bg.texture);
    sfMusic_destroy(all->m.music_menu);
}

void event_menu(all_t *all)
{
    if (all->e.ev.type == sfEvtMouseButtonPressed){
        if (all->mp.x > 100 && all->mp.x < 401 &&
           all->mp.y > 200 && all->mp.y < 298){
            all->bm.rect.width = 603;
            all->bm.rect.left = 310;
            distroy_menu(all);
            game(all);
            return;
        }
        if (all->mp.x > 1520 && all->mp.x < 1803 &&
           all->mp.y > 200 && all->mp.y < 298){
            all->bm.rect1.width = 603;
            all->bm.rect1.left = 310;
            distroy_menu(all);
            help(all);
        }
        if (all->mp.x > 100 && all->mp.x < 401 &&
           all->mp.y > 700 && all->mp.y < 798){
            all->bm.rect2.width = 603;
            all->bm.rect2.left = 310;
            distroy_menu(all);
            sfRenderWindow_close(all->b.window);
        }
    }
    if (all->e.ev.type == sfEvtClosed){
        distroy_menu(all);
        sfRenderWindow_close(all->b.window);
    }
}

void menu(all_t *all)
{
    init_all(all);
    while (sfRenderWindow_isOpen(all->b.window)) {
        sfRenderWindow_clear(all->b.window, sfBlack);
        display(all);
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            event_menu(all);
        }
        sfRenderWindow_display(all->b.window);
    }
}

int main (int ac, char **av)
{
    all_t all;
    
    create_window(&all);
    menu(&all);
}
