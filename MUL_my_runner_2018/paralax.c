/*
** EPITECH PROJECT, 2019
** my_runer
** File description:
** parlax
*/

#include "include.h"

void init(all_t *all)
{
    all->ba.sprite = sfSprite_create();
    all->ba.texture = sfTexture_createFromFile("back_ground1.png", NULL);
    sfSprite_setTexture(all->ba.sprite, all->ba.texture, sfTrue);
    all->bb.sprite = sfSprite_create();
    all->bb.texture = sfTexture_createFromFile("bg2a.png", NULL);
    sfSprite_setTexture(all->bb.sprite, all->bb.texture, sfTrue);
    all->bc.sprite = sfSprite_create();
    all->bc.texture = sfTexture_createFromFile("BG.png", NULL);
    sfSprite_setTexture(all->bc.sprite, all->bc.texture, sfTrue);
    all->bd.sprite = sfSprite_create();
    all->bd.texture = sfTexture_createFromFile("bg3a.png", NULL);
    sfSprite_setTexture(all->bd.sprite, all->bd.texture, sfTrue);
    all->be.sprite = sfSprite_create();
    all->be.texture = sfTexture_createFromFile("bg34.png", NULL);
    sfSprite_setTexture(all->be.sprite, all->be.texture, sfTrue);
    all->mvb.p1.x = 0;
    all->mvb.p2.x = 0;
    all->mvb.p3.x = 0;
    all->mvb.p4.x = 0;
}

void sprite_position(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->ba.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bb.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bc.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->bd.sprite, NULL);
    sfRenderWindow_drawSprite(all->b.window, all->be.sprite, NULL);
}

void mv_back(all_t *all)
{
    all->mvb.p1.x -= 0.3;
    all->mvb.p2.x -= 0.7;
    all->mvb.p3.x -= 1;
    all->mvb.p4.x -= 2,5;
    if(all->mvb.p1.x < -1600)
        all->mvb.p1.x = 0;
    if(all->mvb.p2.x < -1600)
        all->mvb.p2.x = 0;
    if(all->mvb.p3.x < -1600)
        all->mvb.p3.x = 0;
    if(all->mvb.p4.x < -1600)
        all->mvb.p4.x = 0;
    sfSprite_setPosition (all->bb.sprite, all->mvb.p1);
    sfSprite_setPosition (all->bc.sprite, all->mvb.p2);
    sfSprite_setPosition (all->bd.sprite, all->mvb.p3);
    sfSprite_setPosition (all->be.sprite, all->mvb.p4);
}
