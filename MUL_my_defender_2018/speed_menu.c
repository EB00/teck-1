/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** speed menu
*/

#include "my.h"

void init_speed_menu(all_t *all)
{
    all->sm.sprite = sfSprite_create();
    all->sm.texture = sfTexture_createFromFile("speed_menu.png", NULL);
    sfSprite_setTexture(all->sm.sprite, all->sm.texture, sfTrue);
    all->sm.rect.top = 0;
    all->sm.rect.left = 0;
    all->sm.rect.width = 700;
    all->sm.rect.height = 105;
    all->sm.position.x = 1880;
    all->sm.position.y = 850;
}

void speed_menu(all_t *all)
{
    sfSprite_setPosition (all->sm.sprite, all->sm.position);
    sfSprite_setTextureRect(all->sm.sprite, all->sm.rect);
    sfRenderWindow_drawSprite(all->b.window, all->sm.sprite, NULL);
}

void event_speed_menu(all_t *all)
{
    all->sm.position.x = 1230;
}

void second_event_speed_menu(all_t *all)
{
    if (all->mp.x > all->sm.position.x + 50 && all->sm.position.x + 150 > all->mp.x &&
        all->sm.position.y < all->mp.y && all->sm.position.y + 105 > all->mp.y ) {
        if (all->t.nb_tower < 30 && all->mb1.bling >= 100){
            if (all->mb1.bling >= 100) {
                all->t.nb_tower ++;
                all->t.click == 1;
                all->t.position[all->t.nb_tower].y = all->mp.y - 150;
                all->t.position[all->t.nb_tower].x = all->mp.x - 150;
                all->t.savetower += 1;
            }
        }
    }else if (all->mp.x > all->sm.position.x + 200 && all->sm.position.x + 350 > all->mp.x &&
              all->sm.position.y < all->mp.y && all->sm.position.y + 105 > all->mp.y ){
        if(all->t.nb_tower < 30 && all->mb1.bling >= 10) {
            if (all->mb1.bling >= 10) {
                all->t.nb_tower ++;
                all->t.click == 1;
                all->t.position[all->t.nb_tower].y = all->mp.y - 150;
                all->t.position[all->t.nb_tower].x = all->mp.x - 150;
                all->t.savetower += 1;
            }
        }
    }
    if (all->mp.x > all->sm.position.x + 350 && all->sm.position.x + 500 > all->mp.x &&
        all->sm.position.y < all->mp.y && all->sm.position.y + 105 > all->mp.y ){
        if(all->t.nb_tower < 30 && all->mb1.bling > 20){
            if (all->mb1.bling >= 20) {
                all->t.nb_tower ++;
                all->t.click == 1;
                all->t.position[all->t.nb_tower].y = all->mp.y - 150;
                all->t.position[all->t.nb_tower].x = all->mp.x - 150;
                all->t.rect[all->t.nb_tower].top = 340;
                all->t.savetower += 1;
            }
        }
    } else if (all->mp.x > all->sm.position.x + 550 &&
               all->sm.position.x + 700 > all->mp.x &&
               all->sm.position.y < all->mp.y && all->sm.position.y + 105 > all->mp.y ){
        if(all->t.nb_tower < 30 && all->mb1.bling >= 30){
            if (all->mb1.bling >= 30){
                all->t.nb_tower ++;
                all->t.click == 1;
                all->t.position[all->t.nb_tower].y = all->mp.y - 150;
                all->t.position[all->t.nb_tower].x = all->mp.x - 150;
                all->t.rect[all->t.nb_tower].top = 750;
                all->t.savetower += 1;
            }
        }
    }
}
