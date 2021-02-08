/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** life & mob
*/

#include "include.h"

void init_life(all_t *all)
{
    all->l.sprite = sfSprite_create();
    all->l.texture = sfTexture_createFromFile("LIFE.png", NULL);
    sfSprite_setTexture(all->l.sprite, all->l.texture, sfTrue);
    all->l.rect.top = 0;
    all->l.rect.left = 0;
    all->l.rect.width = 200;
    all->l.rect.height = 66;
    all->l.life = 0;
    all->l.position.x = 1396;
    all->l.position.y = 4;
    sfSprite_setPosition (all->l.sprite, all->l.position);
    all->v.victory = 0;
    all->s.tot = 0;
    all->p.verif = 0;
    all->p.jump = 0;
    all->p.nb_jump = 0;
    all->p.pos_jump;
    all->p.move = 0;
    all->s.compt1 = 0;
    all->s.compt = 0;
}

void life(all_t *all)
{
    sfSprite_setTextureRect(all->l.sprite, all->l.rect);
    sfRenderWindow_drawSprite(all->b.window, all->l.sprite, NULL);
}

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
