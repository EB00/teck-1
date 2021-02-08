/*
** EPITECH PROJECT, 2019
** score & musique
** File description:
** my runner
*/

#include "include.h"

void score_rec(all_t *all)
{
    all->s.rect.top = 0;
    all->s.rect.left = 0;
    all->s.rect.width = 40;
    all->s.rect.height = 40;
    all->s.rect1.top = 0;
    all->s.rect1.left = 0;
    all->s.rect1.width = 40;
    all->s.rect1.height = 40;
    all->s.rect2.top = 0;
    all->s.rect2.left = 0;
    all->s.rect2.width = 40;
    all->s.rect2.height = 40;
}

void init_score(all_t *all)
{
    all->s.sprite1 = sfSprite_create();
    all->s.sprite2 = sfSprite_create();
    all->s.sprite3 = sfSprite_create();
    all->s.texture1 = sfTexture_createFromFile("index.jpg", NULL);
    all->s.texture2 = sfTexture_createFromFile("index.jpg", NULL);
    all->s.texture3 = sfTexture_createFromFile("index.jpg", NULL);
    sfSprite_setTexture(all->s.sprite1, all->s.texture1, sfTrue);
    sfSprite_setTexture(all->s.sprite2, all->s.texture2, sfTrue);
    sfSprite_setTexture(all->s.sprite3, all->s.texture3, sfTrue);
    score_rec(all);
    all->s.rect.top = 0;
    all->s.rect.left = 0;
    all->s.rect.width = 40;
    all->s.rect.height = 40;
    all->s.position1.x = 1350;
    all->s.position1.y = 10;
    all->s.position3.x = 1300;
    all->s.position3.y = 10;
    all->s.position2.x = 1250;
    all->s.position2.y = 10;
}

void score(all_t *all)
{
    sfSprite_setPosition (all->s.sprite1, all->s.position1);
    sfSprite_setPosition (all->s.sprite2, all->s.position2);
    sfSprite_setPosition (all->s.sprite3, all->s.position3);
    sfSprite_setTextureRect(all->s.sprite1, all->s.rect);
    sfSprite_setTextureRect(all->s.sprite2, all->s.rect1);
    sfSprite_setTextureRect(all->s.sprite3, all->s.rect2);
    if (all->s.compt > 9){
        all->s.compt = 0;
        all->s.compt1 ++;
        all->s.rect.left = 0;
        all->s.rect2.left += 41;
    }
    if (all->s.compt1 > 9){
        all->s.compt1 = 0;
        all->s.compt2 ++;
        all->s.rect1.left = 0;
        all->s.rect2.left += 41;
    }
    sfRenderWindow_drawSprite(all->b.window, all->s.sprite1, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->s.sprite2, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->s.sprite3, NULL);
}

void init_sound(all_t *all)
{
    all->m.music = sfMusic_createFromFile("SHIKABANE.ogg");
    all->m.music1 = sfMusic_createFromFile("JUMP.ogg");
    all->m.music2 = sfMusic_createFromFile("HURT.ogg");
    sfMusic_play(all->m.music);
}
