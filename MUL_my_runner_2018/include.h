/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** include.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>


#ifndef _INCLUDE_H_
#define _INCLUDE_H_

typedef struct back_ground{
    sfRenderWindow *window;
    sfVideoMode mode;
}back_t;

typedef struct caractere{
    sfTexture* texture;
    sfSprite* sprite;
}cara_t;

typedef struct musique{
    sfMusic *music;
    sfMusic *music1;
    sfMusic *music2;
    sfMusic *music3;
    sfMusic *music4;
}music_t;

typedef struct event{
    sfEvent ev;
}event_t;

typedef struct backg1{
    sfTexture* texture;
    sfSprite* sprite;
}bg1_t;

typedef struct backg2{
    sfTexture* texture;
    sfSprite* sprite;
}bg2_t;

typedef struct backg3{
    sfTexture* texture;
    sfSprite* sprite;
}bg3_t;

typedef struct backg4{
    sfTexture* texture;
    sfSprite* sprite;
}bg4_t;

typedef struct backg5{
    sfTexture* texture;
    sfSprite* sprite;
}bg5_t;

typedef struct mv_back1{
    sfVector2f p1;
    sfVector2f p2;
    sfVector2f p3;
    sfVector2f p4;
}mvb1_t;

typedef struct players_t{
    sfVector2f position;
    sfIntRect rect;
    sfTexture* texture;
    sfSprite* sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
    int verif;
    int jump;
    int nb_jump;
    int pos_jump;
    int move;
}player_t;

typedef struct timer_t{
    sfClock *clock;
    sfTime time;
    float seconds;
}times_t;

typedef struct mob1_t{
    sfVector2f position;
    sfIntRect rect;
    sfTexture* texture;
    sfSprite* sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
}m1_t;

typedef struct scores_t{
    
    int compt;
    int compt1;
    int compt2;
    int tot;
    sfVector2f position1;
    sfVector2f position2;
    sfVector2f position3;
    sfTexture* texture1;
    sfTexture* texture2;
    sfTexture* texture3;
    sfSprite* sprite1;
    sfSprite* sprite2;
    sfSprite* sprite3;
    sfIntRect rect;
    sfIntRect rect1;
    sfIntRect rect2;
}score_t;

typedef struct lifes_t{
    int life;
    sfVector2f position;
    sfIntRect rect;
    sfTexture* texture;
    sfSprite* sprite;
}life_t;

typedef struct victory_t{
    int victory;
}victor_t;

typedef struct all{
    back_t  b;
    bg1_t ba;
    bg2_t bb;
    bg3_t bc;
    bg4_t bd;
    bg5_t be;
    mvb1_t mvb;
    cara_t c;
    music_t m;
    event_t e;
    player_t p;
    times_t t;
    score_t s;
    m1_t mb1;
    life_t l;
    victor_t v;
}all_t;

void init(all_t *all);
void sprite_position(all_t *all);
void mv_back(all_t *all);
void init_player(all_t *all);
void player(all_t *all);
void score_rec(all_t *all);
void init_life(all_t *all);
void life(all_t *all);
void init_mob(all_t *all);
void mob(all_t *all);
void jump(all_t *all);
void gravity1(all_t *all);
void fall(all_t *all);
void score_rec(all_t *all);
void init_score(all_t *all);
void score(all_t *all);
void init_sound(all_t *all);
void boom(all_t *all);
int victory(all_t *all, int ac, char **av);
void distroy(all_t *all);
#endif
