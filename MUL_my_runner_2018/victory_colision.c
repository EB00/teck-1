/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** victory et collision.c
*/
#include "include.h"

void boom(all_t *all)
{
    float a = all->p.position.y + 80;
    float b = all->p.position.x + 70;
    float c = all->mb1.position.y + 38;
    float d = all->mb1.position.y + 47;

    if((all->p.position.x == all->mb1.position.x) &&
       (all->p.position.y <= all->mb1.position.y && a >= all->mb1.position.y)){
        all->l.rect.left -= 66;
        all->l.life -= 1;
        sfMusic_play(all->m.music2);
    }else if(all->p.position.x == all->mb1.position.x){
        all->s.compt ++;
        all->s.rect.left += 41;
        all->s.tot += 1;
    }
}

int victory(all_t *all, int ac, char **av)
{
    if(all->s.tot >= 10){
        all->v.victory = 1;
        distroy(all);
        return (1);
    }
    if(all->l.life <= -3){
        all->v.victory = 2;
        distroy(all);
        return (1);
    }
    return (0);
}

void destroy(all_t *all)
{
sfSprite_destroy(all->s.sprite3);
    sfSprite_destroy(all->l.sprite);
    sfTexture_destroy(all->ba.texture);
    sfTexture_destroy(all->bb.texture);
    sfTexture_destroy(all->bc.texture);
    sfTexture_destroy(all->bd.texture);
    sfTexture_destroy(all->be.texture);
    sfTexture_destroy(all->p.texture);
    sfTexture_destroy(all->mb1.texture);
    sfTexture_destroy(all->s.texture1);
    sfTexture_destroy(all->s.texture2);
    sfTexture_destroy(all->s.texture3);
    sfTexture_destroy(all->l.texture);
    sfClock_destroy(all->mb1.clock);
    sfRenderWindow_destroy(all->b.window);
}

void distroy(all_t *all)
{
    sfMusic_destroy(all->m.music);
    sfMusic_destroy(all->m.music1);
    sfMusic_destroy(all->m.music2);
    sfSprite_destroy(all->ba.sprite);
    sfSprite_destroy(all->bb.sprite);
    sfSprite_destroy(all->bc.sprite);
    sfSprite_destroy(all->bd.sprite);
    sfSprite_destroy(all->be.sprite);
    sfSprite_destroy(all->p.sprite);
    sfSprite_destroy(all->mb1.sprite);
    sfSprite_destroy(all->s.sprite1);
    sfSprite_destroy(all->s.sprite2);
    destroy(all);
}
