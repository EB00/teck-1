/*
** EPITECH PROJECT, 2019
** minishel 2
** File description:
** fonction2
*/
#include <stdlib.h>
#include "include.h"

void exit_function(ar_t separ)
{
    int val = 0;
    
    if (separ.buffer[1] == NULL)
        exit (0);
    else if (separ.buffer[2] != NULL) {
        write(1, "exit: Expression Syntax.\n", 25);
        return;
    }
    for (int i = 0; separ.buffer[1][i] != '\0'; i++) {
        if (separ.buffer[1][i] < '1' || separ.buffer[1][i] > '9') {
            write(1, "exit: Expression Syntax.\n", 25);
            return;
        }
    }
    val = my_getnbr(separ.buffer[1]);
    exit (val);
}
