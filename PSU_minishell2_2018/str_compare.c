
/*
** EPITECH PROJECT, 2019
** str_compare
** File description:
** str_compare
*/

#include <stdio.h>
#include <unistd.h>
#include "include.h"

int my_str_compare(char *str, char *compare)
{
    int i = my_strlen(str);
    int o = my_strlen(compare);
    int compt = 0;

    if (i != o)
        return (84);
    while (compt != i) {
        if (str[compt] != compare[compt]) {
            return (84);
        }
        compt++;
    }
    return (1);
}

int my_str_compare1(char *str, char *compare)
{
    int i = my_strlen(compare);
    int o = my_strlen(compare);
    int compt = 0;

    while (compt != i) {
        if (str[compt] != compare[compt]) {
            return (84);
        }
        compt++;
    }
    return (1);
}
