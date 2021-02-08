/*
** EPITECH PROJECT, 2019
** my_defenders
** File description:
** my.h
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

typedef struct back_ground_t{
    sfRenderWindow *window;
    sfVideoMode mode;
}back_t;

typedef struct back_g_t{
    sfTexture* texture;
    sfSprite* sprite;
}back_ground_t;

typedef struct event{
    sfEvent ev;
    int victory;
}event_t;

typedef struct mouse_pos{
    int x;
    int y;
}mouse_t;

typedef struct button_menu_t{
    sfVector2f position;
    sfVector2f position1;
    sfVector2f position2;
    sfIntRect rect;
    sfIntRect rect1;
    sfIntRect rect2;
    sfTexture *texture;
    sfTexture *texture1;
    sfTexture *texture2;
    sfSprite *sprite;
    sfSprite *sprite1;
    sfSprite *sprite2;
}button_menu_t;

typedef struct musique{
    sfMusic *music_menu;
    sfMusic *music_click_button;
    sfMusic *music_button;
}music_t;

typedef struct mob1_t{
    sfVector2f position;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
    int pos;
    int speed;
    int end;
    int life;
    int wave;
    int bling;
}m1_t;

typedef struct speed_menu_t{
    sfVector2f position;
    sfIntRect rect;
    sfTexture* texture;
    sfSprite* sprite;
}speed_menu_t;

typedef struct tower_t{
    sfVector2f* position;
    sfIntRect *rect;
    sfTexture** texture;
    sfSprite** sprite;
    int* lvl;
    int power;
    int nb_tower;
    int ltower;
    int click;
    int savetower;
}tower_t;

typedef struct escape_t{
    sfVector2f position;
    sfTexture* texture;
    sfSprite* sprite;
}escape_t;

typedef struct lifes_t{
    int life;
    sfVector2f position;
    sfIntRect rect;
    sfTexture* texture;
    sfSprite* sprite;
}life_t;

typedef struct all_t{
    back_t b;
    back_ground_t bg;
    event_t e;
    mouse_t mp;
    button_menu_t bm;
    music_t m;
    m1_t mb1;
    speed_menu_t sm;
    tower_t t;
    escape_t es;
    life_t ll;
}all_t;

void init_button_menu(all_t *all);
void display_button_menu(all_t *all);
void mob(all_t *all);
void init_mob(all_t *all);
void game(all_t *all);
void menu(all_t *all);
void help(all_t *all);
void init_speed_menu(all_t *all);
void speed_menu(all_t *all);
void event_speed_menu(all_t *all);
void init_tower(all_t *all);
void tower(all_t *all);
void tower_event(all_t *all);
void second_event_speed_menu(all_t *all);
void destroy(all_t *all);
void display_button_escape(all_t *all);
void init_button_escape(all_t *all);
int event_escape(all_t *all, int *off);
void game_over(all_t *all);
void init_life(all_t *all);
void life(all_t *all);
void shoot_mob(all_t *all);
#endif
