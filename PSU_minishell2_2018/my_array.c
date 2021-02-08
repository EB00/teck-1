/*
** EPITECH PROJECT, 2019
** my_aray
** File description:
** my_str_to_world_aray
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}

int compt_space(char *av)
{
    int i = 0;
    int nb_space = 0;

    while (av[i] != 0) {
        if (av[i] == ':') {
            nb_space++;
        }
        i++;
    }
    return (nb_space);
}

int arrays(int ac, char *av, ar_t *array)
{
    int compt = 0;
    int space = 0;
    int x = 0;
    int i = 0;
    int o = 0;

    compt = compt_space(av);
    compt += 2;
    array->buffer = malloc(sizeof(char *) * compt);
    while (i != (compt -1)) {
        array->buffer[i] = my_calloc(sizeof(char *) * compt);
        i++;
    }
    i = 0;
    while (av[i] != '\0') {
        if (av[i]  == ':') {
            o++;
            x = 0;
            if (av[i] == ':')
                i++;
        }
        array->buffer[o][x] = av[i];
        x++;
        i++;
    }
}
