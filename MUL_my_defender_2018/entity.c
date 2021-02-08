/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** entity
*/

#include "my.h"

void init_mob(all_t *all)
{
    all->mb1.sprite = sfSprite_create();
    all->mb1.texture = sfTexture_createFromFile("phoenix.png", NULL);
    sfSprite_setTexture(all->mb1.sprite, all->mb1.texture, sfTrue);
    all->mb1.rect.top = 188;
    all->mb1.rect.left = 0;
    all->mb1.rect.width = 94;
    all->mb1.rect.height = 96;
    all->mb1.position.x = 0;
    all->mb1.position.y = 646;
    all->mb1.life = 100;
    all->mb1.pos = 0;
    all->mb1.speed = 3;
    all->mb1.wave = 1;
    all->mb1.clock = sfClock_create();
}

void past_finding_part2(all_t *all)
{
    if(all->mb1.pos == 4) {
        if (all->mb1.position.x >= 1170 && all->mb1.position.y >= 780){
            all->mb1.pos++;
            all->mb1.rect.top = 292;
        }
        all->mb1.position.x += all->mb1.speed;
    }else if(all->mb1.pos == 5) {
        if (all->mb1.position.x >= 1170 && all->mb1.position.y <= 520){
            all->mb1.pos ++;
            all->mb1.rect.top = 188;
        }
        all->mb1.position.y -= all->mb1.speed;
    }
    if(all->mb1.pos == 6) {
        if (all->mb1.position.x >= 1800 && all->mb1.position.y <= 520) {
            all->mb1.pos ++;
            all->mb1.rect.top = 188;
        }
        all->mb1.position.x += all->mb1.speed;
    }else if(all->mb1.position.x > 1800) {
        all->mb1.position.x = 0;
        all->mb1.position.y = 646;
        all->mb1.pos = 0;
        all->mb1.rect.top = 188;
        all->mb1.life = 100 * all->mb1.wave;
        all->mb1.wave++;
    }
}

void past_finding(all_t *all)
{
    if (all->mb1.pos == 0 ) {
        if (all->mb1.position.x >= 280 && all->mb1.position.y == 646) {
            all->mb1.pos++;
            all->mb1.rect.top = 282;
        }
        all->mb1.position.x += all->mb1.speed;
    }else if(all->mb1.pos == 1) {
        if (all->mb1.position.x >= 280 && all->mb1.position.y <= 268){
            all->mb1.pos++;
            all->mb1.rect.top = 188;
        }
        all->mb1.position.y -= all->mb1.speed;
    }
    if (all->mb1.pos == 2) {
        if (all->mb1.position.x >= 660 && all->mb1.position.y <= 300) {
            all->mb1.pos ++;
            all->mb1.rect.top = 0;
        }
        all->mb1.position.x += all->mb1.speed;
    }else if (all->mb1.pos == 3) {
        if (all->mb1.position.x >= 660 && all->mb1.position.y >= 780) {
            all->mb1.pos++;
            all->mb1.rect.top = 188;
        }
        all->mb1.position.y += all->mb1.speed;
    }
    past_finding_part2(all);
}

void mob(all_t *all)
{
    all->mb1.time = sfClock_getElapsedTime(all->mb1.clock);
    all->mb1.seconds = all->mb1.time.microseconds / 10000000.0;
    if(all->mb1.seconds > 0.02) {
        all->mb1.rect.left += 94,5;
        if(all->mb1.rect.left > 235)
            all->mb1.rect.left = 0;
        sfClock_restart(all->mb1.clock);
    }
    past_finding(all);
    sfSprite_setPosition (all->mb1.sprite, all->mb1.position);
    sfSprite_setTextureRect(all->mb1.sprite, all->mb1.rect);
    sfRenderWindow_drawSprite(all->b.window, all->mb1.sprite, NULL);
    
}
