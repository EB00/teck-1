/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** life & mob
*/

#include "my.h"

void init_life(all_t *all)
{
    all->ll.sprite = sfSprite_create();
    all->ll.texture = sfTexture_createFromFile("LIFE.png", NULL);
    sfSprite_setTexture(all->ll.sprite, all->ll.texture, sfTrue);
    all->ll.rect.top = 0;
    all->ll.rect.left = 0;
    all->ll.rect.width = 200;
    all->ll.rect.height = 66;
    all->ll.life = 0;
    all->ll.position.x = 1720;
    all->ll.position.y = 4;
    sfSprite_setPosition (all->ll.sprite, all->ll.position);
}

void life(all_t *all)
{
    sfSprite_setTextureRect(all->ll.sprite, all->ll.rect);
    sfRenderWindow_drawSprite(all->b.window, all->ll.sprite, NULL);
    if(all->mb1.position.x > 1800) {
        all->ll.rect.top += 66;
        all->ll.life ++;
    }
    if(all->ll.life > 2) {
        destroy(all);
        all->e.victory = 1;
        game_over(all);
    }
}


void shoot_mob(all_t *all)
{
    sfVector2f pos;

    pos = sfSprite_getPosition(all->mb1.sprite);
    for (int i = 0; i < 30; i++) {
        if (pos.x > all->t.position[i].x - 150 &&
            pos.x < all->t.position[i].x + 450 &&
            pos.y > all->t.position[i].y - 150 &&
            pos.y < all->t.position[i].y + 350 &&
            all->t.rect[all->t.nb_tower].top == 0) {
            all->mb1.life -= 1;
        }
	if (pos.x > all->t.position[i].x - 150 &&
            pos.x < all->t.position[i].x + 450 &&
            pos.y > all->t.position[i].y - 150 &&
            pos.y < all->t.position[i].y + 350 &&
            all->t.rect[all->t.nb_tower].top == 340) {
            all->mb1.life -= 2;
        }
	if (pos.x > all->t.position[i].x - 150 &&
            pos.x < all->t.position[i].x + 450 &&
            pos.y > all->t.position[i].y - 150 &&
            pos.y < all->t.position[i].y + 350 &&
            all->t.rect[all->t.nb_tower].top == 750) {
            all->mb1.life -= 3;
        }
/*        if (pos.x > all->t.position[i].x - 150 &&
	    pos.x < all->t.position[i].x + 450 &&
            pos.y > all->t.position[i].y - 150 &&
            pos.y < all->t.position[i].y + 350) {
            all->mb1.life -= 1;
            printf("life3 == %d\n", all->mb1.life);
            }*/
    }
    if (all->mb1.life < 0) {
        all->mb1.position.x = 0;
        all->mb1.position.y = 646;
        all->mb1.pos = 0;
        all->mb1.rect.top = 188;
        all->mb1.life = 100 * all->mb1.wave;
        all->mb1.wave++;
        all->mb1.bling += 10;
    }
}
