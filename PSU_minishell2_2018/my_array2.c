/*
** EPITECH PROJECT, 2019
** minishel
** File description:
** my_array
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "include.h"

int my_strlen2(char *str)
{
    int i = 0;
    
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int compt_space2(char *av, char val)
{
    int i = 0;
    int nb_space = 0;

    while (av[i] != 0) {
        if (av[i] == val) {
            nb_space++;
        }
        i++;
    }
    return (nb_space);
}

char **new_array(char *str, ar_t *array, char val)
{
    int space = 0;
    int x = 0;
    int y = 0;
    int i = 0;

    space = compt_space2(str, val) + 1;
    array->buffer = malloc(sizeof(char *) * space);
    for (i = 0; i < space; i++)
        array->buffer[i] = my_calloc(sizeof(char) * my_strlen2(str) + 1);
    for (i = 0; str[i] != '\0';) {
        if (str[i] == val || str[i] == '\t') {
            while (str[i] == val || str[i] == '\t')
                i++;
            if (x > 0) {
                y++;
                x = 0;
            }
        }
        array->buffer[y][x] = str[i];
        i++;
        x++;
    }
    array->buffer[y + 1] = NULL;
    return (array->buffer);
}
