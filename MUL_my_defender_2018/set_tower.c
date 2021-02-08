
/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set_tower
*/
#include "my.h"

void init_tower(all_t *all)
{
    all->t.texture = malloc(sizeof(sfTexture*) * 30);
    all->t.sprite = malloc(sizeof(sfSprite*) * 30);
    all->t.position = malloc(sizeof(sfVector2f *) * 30);
    all->t.rect = malloc(sizeof(sfIntRect) * 30);

    for(int i = 0; i < 30; i++) {
        all->t.sprite[i] = sfSprite_create();
        all->t.texture[i] = sfTexture_createFromFile("Tower.png", NULL);
        sfSprite_setTexture(all->t.sprite[i], all->t.texture[i], sfTrue);
        all->t.rect[i].top = 0;
        all->t.rect[i].left = 10;
        all->t.rect[i].width = 200;
        all->t.rect[i].height = 300;
        all->t.position[i].x = -100;
        all->t.position[i].y = -100;
    }
    all->t.click = 0;
    all->t.nb_tower = 0;
    all->t.savetower = - 1;
}

void tower(all_t *all)
{
    for(int i = 0; i < all->t.nb_tower; i++){
        if (all->t.click == 1 && all->t.position[all->t.savetower].x <  all->mp.x &&
            all->t.position[all->t.savetower].x + 350 > all->mp.x &&
            all->t.position[all->t.savetower].y < all->mp.y &&
            all->t.position[all->t.savetower].y + 287 > all->mp.y) {
            all->t.position[all->t.savetower].x = all->mp.x - 150;
            all->t.position[all->t.savetower].y = all->mp.y - 150;
        }
        if (all->t.click > 1)
            all->t.click = 0;
        sfSprite_setPosition (all->t.sprite[i], all->t.position[i]);
        sfSprite_setTextureRect(all->t.sprite[i], all->t.rect[i]);
        sfRenderWindow_drawSprite(all->b.window, all->t.sprite[i], NULL);
    }
}

void tower_event(all_t *all)
{
    if (all->e.ev.type == sfEvtMouseButtonPressed)
        for(int i = 0; i < all->t.nb_tower; i++) {
            if (all->t.position[all->t.savetower].x <  all->mp.x &&
                all->t.position[all->t.savetower].x + 350 > all->mp.x &&
                all->t.position[all->t.savetower].y < all->mp.y &&
                all->t.position[all->t.savetower].y + 287 > all->mp.y){
                all->t.click = 1;
            }
        }
     if (all->e.ev.type == sfEvtMouseButtonReleased)
                all->t.click = 0;
}
