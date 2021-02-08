/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** player
*/

#include "include.h"

void init_player(all_t *all)
{
    all->p.sprite = sfSprite_create();
    all->p.texture = sfTexture_createFromFile("RoyMustang.png", NULL);
    sfSprite_setTexture(all->p.sprite, all->p.texture, sfTrue);
    all->p.rect.top = 90;
    all->p.rect.left = 10;
    all->p.rect.width = 70;
    all->p.rect.height = 80;
    all->p.position.x = 100;
    all->p.position.y = 700;
    all->p.clock = sfClock_create();
    all->p.verif = 0;
    all->p.jump = 0;
}

void player(all_t *all)
{
    all->p.time = sfClock_getElapsedTime(all->p.clock);
    all->p.seconds = all->p.time.microseconds / 10000000.0;
    if(all->p.verif == 0){
        if(all->p.seconds > 0.01) {
            all->p.rect.left += 71;
            if(all->p.rect.left > 420)
            all->p.rect.left = 10;
            sfClock_restart(all->p.clock);
        }
    }
    sfSprite_setPosition (all->p.sprite, all->p.position);
    sfSprite_setTextureRect(all->p.sprite, all->p.rect);
    sfRenderWindow_drawSprite(all->b.window, all->p.sprite, NULL);
}
