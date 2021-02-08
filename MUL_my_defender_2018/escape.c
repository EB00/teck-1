/*
** EPITECH PROJECT, 2019
** ne my_defender
** File description:
** escape
*/

#include "my.h"

void init_button_escape_part2(all_t *all)
{
    all->bm.sprite2 = sfSprite_create();
    all->bm.texture2 = sfTexture_createFromFile("button_menu1.png", NULL);
    sfSprite_setTexture(all->bm.sprite2, all->bm.texture2, sfTrue);
    all->bm.rect2.top = 0;
    all->bm.rect2.left = 0;
    all->bm.rect2.width = 250;
    all->bm.rect2.height = 98;
    all->bm.position2.x = 780;
    all->bm.position2.y = 600;
    all->es.sprite = sfSprite_create();
    all->es.texture = sfTexture_createFromFile("escape.png", NULL);
    sfSprite_setTexture(all->es.sprite, all->es.texture, sfTrue);
    all->es.position.x = 670;
    all->es.position.y = 150;
}

void init_button_escape(all_t *all)
{
    all->bm.sprite = sfSprite_create();
    all->bm.texture = sfTexture_createFromFile("button_menu1.png", NULL);
    sfSprite_setTexture(all->bm.sprite, all->bm.texture, sfTrue);
    all->bm.sprite1 = sfSprite_create();
    all->bm.texture1 = sfTexture_createFromFile("button_menu1.png", NULL);
    sfSprite_setTexture(all->bm.sprite1, all->bm.texture1, sfTrue);
    all->bm.rect.top = 0;
    all->bm.rect.left = 0;
    all->bm.rect.width = 250;
    all->bm.rect.height = 98;
    all->bm.rect1.top = 0;
    all->bm.rect1.left = 0;
    all->bm.rect1.width = 255;
    all->bm.rect1.height = 98;
    all->bm.position.x = 780;
    all->bm.position.y = 300;
    all->bm.position1.x = 780;
    all->bm.position1.y = 450;
    init_button_escape_part2(all);
}

void display_button_escape_part2(all_t *all)
{
    sfSprite_setPosition (all->bm.sprite2, all->bm.position2);
    sfSprite_setTextureRect(all->bm.sprite2, all->bm.rect2);
    if(all->mp.x > 780 && all->mp.x <1101 &&
       all->mp.y > 600 && all->mp.y < 698) {
        all->bm.rect2.width = 603;
        all->bm.rect2.left = 328;
    }else {
        all->bm.rect2.width = 290;
        all->bm.rect2.left = 0;
    }
    sfRenderWindow_drawSprite(all->b.window, all->es.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite1, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite2, NULL);
}

void display_button_escape(all_t *all)
{
    sfSprite_setPosition (all->es.sprite, all->es.position);
    sfSprite_setPosition (all->bm.sprite, all->bm.position);
    sfSprite_setTextureRect(all->bm.sprite, all->bm.rect1);
    sfSprite_setPosition (all->bm.sprite1, all->bm.position1);
    sfSprite_setTextureRect(all->bm.sprite1, all->bm.rect);
    if(all->mp.x > 780 && all->mp.x < 1101 &&
       all->mp.y > 450 && all->mp.y < 548) {
        all->bm.rect.width = 603;
        all->bm.rect.left = 328;
    }else {
    all->bm.rect.width = 290;
    all->bm.rect.left = 0;
    }
    if(all->mp.x > 780 && all->mp.x < 1101 &&
       all->mp.y > 300 && all->mp.y < 398) {
        all->bm.rect1.width = 603;
        all->bm.rect1.left = 328;
    }else {
  all->bm.rect1.width = 290;
    all->bm.rect1.left = 0;
    }
    display_button_escape_part2(all);
}

int event_escape(all_t *all, int *off)
{
    if (all->e.ev.type == sfEvtMouseButtonPressed){
        if(all->mp.x > 780 && all->mp.x < 1101 &&
           all->mp.y > 450 && all->mp.y < 548){
            all->bm.rect.width = 603;
            all->bm.rect.left = 310;
            sfMusic_destroy(all->m.music_menu);
            menu(all);
//            return (1);
        }
        if(all->mp.x > 780 && all->mp.x < 1101 &&
           all->mp.y > 300 && all->mp.y < 398){
            all->bm.rect1.width = 603;
            all->bm.rect1.left = 310;
            *off =*off +1;
        }
        if(all->mp.x > 780 && all->mp.x < 1101 &&
           all->mp.y > 600 && all->mp.y < 698){
            all->bm.rect2.width = 603;
            all->bm.rect2.left = 310;
            sfRenderWindow_close(all->b.window);
        }
    }
    if (all->e.ev.type == sfEvtClosed){
        sfRenderWindow_close(all->b.window);
    }
    return (0);
}
