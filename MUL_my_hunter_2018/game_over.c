/*
** EPITECH PROJECT, 2019
** game_over
** File description:
** my_runner
*/

#include "include.h"

void create_window(all_t *all)
{
    sfUint32 parm = sfResize | sfClose;
    all->b.mode = (sfVideoMode){.width = 1600, .height = 871, .bitsPerPixel = 32};
    all->b.window = sfRenderWindow_create(all->b.mode, "MY_RUNNER", parm, NULL);
    sfRenderWindow_setFramerateLimit(all->b.window, 100);

}

void inite(all_t *all)
{
    all->ba.sprite = sfSprite_create();
    all->ba.texture = sfTexture_createFromFile("GAME_OVER.png", NULL);
    sfSprite_setTexture(all->ba.sprite, all->ba.texture, sfTrue);
}

void sprites_position(all_t *all)
{
    sfRenderWindow_drawSprite(all->b.window, all->ba.sprite, NULL);
}

void init_sound(all_t *all){
    all->m.music = sfMusic_createFromFile("END.ogg");
    sfMusic_play(all->m.music);
}

int game_over(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));

    
    create_window(all);
    init(all);
    inite_score(all);
    init_sound(all);
    init_player(all);
    while (sfRenderWindow_isOpen(all->b.window)) {
        sfRenderWindow_clear(all->b.window, sfBlack);
        sprites_position(all);
        score(all);
	player(all);
	while (sfRenderWindow_pollEvent(all->b.window, &all->e.ev)){
            if (all->e.ev.type == sfEvtMouseButtonPressed){
//		game(ac, av);
            }
            if (all->e.ev.type == sfEvtClosed){
		sfRenderWindow_close(all->b.window);
            }
        }
        sfRenderWindow_display(all->b.window);
    }
    sfRenderWindow_destroy(all->b.window);
    return(0);

}
