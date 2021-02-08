/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** gravity
*/
#include "include.h"

void jump(all_t *all)
{
    all->p.nb_jump += 1;
    if (all->p.nb_jump <= 2){
    all->p.verif = 1;
    all->p.jump = (all->p.position.y - 100);
    all->p.rect.left = 0;
    all->p.move = all->p.position.y - 25;
    sfMusic_play(all->m.music1);
    }
}

void gravity1(all_t *all)
{
    if (all->p.seconds > 0.0001 && all->p.verif == 1) {
        if (all->p.position.y > all->p.jump){
            all->p.position.y -= 2;
            all->p.rect.top = 570;
            all->p.rect.width = 55;
            all->p.rect.height = 90;
            all->p.rect.left = 54;
        }
        if (all->p.position.y <= all->p.jump){
            all->p.verif = 2;
        }
    }
}

void fall(all_t *all)
{
    if(all->p.seconds > 0.0001 && all->p.verif == 2) {
        if(all->p.position.y <= 700){
            all->p.position.y += 3;
            all->p.rect.left = 305;
            all->p.rect.width = 65;
        }
        if(all->p.position.y >= 700){
            all->p.verif = 0;
            all->p.nb_jump = 0;
            all->p.rect.top = 90;
            all->p.rect.left = 10;
            all->p.rect.width = 70;
            all->p.rect.height = 80;
            all->p.position.x = 100;
            all->p.position.y = 700;
        }
    }
}
