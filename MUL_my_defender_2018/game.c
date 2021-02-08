/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** game
*/
#include "my.h"

void init_back_ground_game(all_t *all)
{
    all->bg.sprite = sfSprite_create();
    all->bg.texture = sfTexture_createFromFile("404.png", NULL);
    sfSprite_setTexture(all->bg.sprite, all->bg.texture, sfTrue);
}

void init_sound_game(all_t *all)
{
    all->m.music_menu = sfMusic_createFromFile("game.ogg");
    sfMusic_setLoop(all->m.music_menu, 1);
    sfMusic_play(all->m.music_menu);
}

void init_all_game(all_t *all)
{
    all->mp.x = 0;
    all->mp.y = 0;
    init_back_ground_game(all);
    init_sound_game(all);
    init_mob(all);
    init_speed_menu(all);
    init_tower(all);
    init_life(all);
    all->mb1.bling == 19;
}

void display_game(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->bg.sprite, NULL);
    all->mp.x = sfMouse_getPositionRenderWindow(all->b.window).x;
    all->mp.y = sfMouse_getPositionRenderWindow(all->b.window).y;
    mob(all);
    speed_menu(all);
    if (all->sm.position.x <  all->mp.x && all->sm.position.x + 700 > all->mp.x &&
        all->sm.position.y < all->mp.y && all->sm.position.y + 105 > all->mp.y )
        event_speed_menu(all);
    else                                                                          
        all->sm.position.x = 1880;
    tower(all);
    life(all);
    shoot_mob(all);
    if (all->mb1.wave >= 5) {
        all->e.victory = 0;
        destroy(all);
        game_over(all);
    }
    printf("wave == %d\n", all->mb1.wave);
}

void destroy(all_t *all)
{
    sfSprite_destroy(all->bg.sprite);
    sfTexture_destroy(all->bg.texture);
    sfMusic_destroy(all->m.music_menu);
}

void wait(all_t *all)
{
    int off = 0;

    init_button_escape(all);
    all->mp.x = 0;
    all->mp.y = 0;
    while (off == 0 && sfRenderWindow_isOpen(all->b.window)) {
        display_button_escape(all);
        all->mp.x = sfMouse_getPositionRenderWindow(all->b.window).x;
        all->mp.y = sfMouse_getPositionRenderWindow(all->b.window).y;
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            if (event_escape(all, &off) == 1)
                off = 1;
        }
        sfRenderWindow_display(all->b.window);
    }
}

void game(all_t *all)
{
    init_all_game(all);
    while(sfRenderWindow_isOpen(all->b.window)){
        sfRenderWindow_clear(all->b.window, sfBlack);
        display_game(all);
        while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            tower_event(all);
            if (all->e.ev.type == sfEvtMouseButtonPressed){
                second_event_speed_menu(all);
            }
            if (all->e.ev.type == sfEvtClosed){
                destroy(all);
                sfRenderWindow_close(all->b.window);
            }
            if (all->e.ev.key.code == (sfKeyEscape)) {
                 wait(all);
            }
        }
	sfRenderWindow_display(all->b.window);
    }
}
