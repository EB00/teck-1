/*
** EPITECH PROJECT, 2019
** my_runner 
** File description:
** entity
*/

#include "include.h"

void init_mob(all_t *all)
{
    all->mb1.sprite = sfSprite_create();
    all->mb1.texture = sfTexture_createFromFile("76878.png", NULL);
    sfSprite_setTexture(all->mb1.sprite, all->mb1.texture, sfTrue);
    all->mb1.rect.top = 40;
    all->mb1.rect.left = 00;
    all->mb1.rect.width = 47;
    all->mb1.rect.height = 38;
    all->mb1.position.x = 1600;
    all->mb1.position.y = 750;
    all->mb1.clock = sfClock_create();
}

void mob(all_t *all)
{
    all->mb1.time = sfClock_getElapsedTime(all->mb1.clock);
    all->mb1.seconds = all->mb1.time.microseconds / 10000000.0;
        if(all->mb1.seconds > 0.01) {
            all->mb1.rect.left += 46;
            if(all->mb1.rect.left > 235)
            all->mb1.rect.left = 0;
            sfClock_restart(all->mb1.clock);
        }
            all->mb1.position.x -= 3;
            if(all->mb1.position.x < 0)
                all->mb1.position.x = 1600;
    sfSprite_setPosition (all->mb1.sprite, all->mb1.position);
    sfSprite_setTextureRect(all->mb1.sprite, all->mb1.rect);
    sfRenderWindow_drawSprite(all->b.window, all->mb1.sprite, NULL);
}
