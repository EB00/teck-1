/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** button
*/
#include "my.h"

void init_button_part2(all_t *all)
{
    all->bm.sprite2 = sfSprite_create();
    all->bm.texture2 = sfTexture_createFromFile("button_menu1.png", NULL);
     sfSprite_setTexture(all->bm.sprite2, all->bm.texture2, sfTrue);
    all->bm.rect2.top = 0;
    all->bm.rect2.left = 0;
    all->bm.rect2.width = 250;
    all->bm.rect2.height = 98;
    all->bm.position2.x = 100;
    all->bm.position2.y = 700;
}

void init_button_menu(all_t *all)
{
    all->bm.sprite = sfSprite_create();
    all->bm.texture = sfTexture_createFromFile("button_menu1.png", NULL);
    sfSprite_setTexture(all->bm.sprite, all->bm.texture, sfTrue);
    all->bm.sprite1 = sfSprite_create();
    all->bm.texture1 = sfTexture_createFromFile("button_menu2.png", NULL);
    sfSprite_setTexture(all->bm.sprite1, all->bm.texture1, sfTrue);
    all->bm.rect.top = 0;
    all->bm.rect.left = 0;
    all->bm.rect.width = 250;
    all->bm.rect.height = 98;
    all->bm.rect1.top = 0;
    all->bm.rect1.left = 0;
    all->bm.rect1.width = 250;
    all->bm.rect1.height = 98;
    all->bm.position.x = 1520;
    all->bm.position.y = 200;
    all->bm.position1.x = 100;
    all->bm.position1.y = 200;
    init_button_part2(all);
}

void display_button_part2(all_t *all)
{
    sfSprite_setPosition (all->bm.sprite2, all->bm.position2);
    sfSprite_setTextureRect(all->bm.sprite2, all->bm.rect2);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite2, NULL);
    if(all->mp.x > 100 && all->mp.x <401 && all->mp.y > 700 && all->mp.y < 798) {
        all->bm.rect2.width = 603;
        all->bm.rect2.left = 328;
    }else {
    all->bm.rect2.width = 290;
    all->bm.rect2.left = 0;
    }
}

void display_button_menu(all_t *all)
{
    sfSprite_setPosition (all->bm.sprite, all->bm.position);
    sfSprite_setTextureRect(all->bm.sprite, all->bm.rect1);
    sfSprite_setPosition (all->bm.sprite1, all->bm.position1);
    sfSprite_setTextureRect(all->bm.sprite1, all->bm.rect);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite1, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bm.sprite, NULL);
    if(all->mp.x > 100 && all->mp.x <401 && all->mp.y > 200 && all->mp.y < 298) {
        all->bm.rect.width = 603;
        all->bm.rect.left = 328;
    }else {
    all->bm.rect.width = 290;
    all->bm.rect.left = 0;
    }
    if(all->mp.x > 1520 && all->mp.x < 1803 && all->mp.y > 200 && all->mp.y < 298) {
        all->bm.rect1.width = 603;
        all->bm.rect1.left = 328;
    }else {
    all->bm.rect1.width = 290;
    all->bm.rect1.left = 0;
    }
    display_button_part2(all);
}
