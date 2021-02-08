/*
** EPITECH PROJECT, 2019
** minishel
** File description:
** fonction.other
*/
#include <stdlib.h>
#include "include.h"

int init_compar(ar_t *comp)
{
    comp->cond = 3;
    comp->buffer = malloc(sizeof(char) * comp->cond);
    comp->buffer[0] = "exit";
    comp->buffer[1] = "echo";
    comp->buffer[2] = "cd";
}

void modif_pwd(char **env)
{
    char compar[] = "PWD=";
    char *recup;
    int i = 0;
    write(1, "cc\n", 3);
    for (i = 0; env[i] != 0; i++) {
        if (my_str_compare1(env[i], compar) == 1) {
            recup = my_calloc(sizeof(char) * (my_strlen1(env[i])));
            recup = env[i];
        }
    }
}

int other_fuction(ar_t separ, char **env, int val, ar_t *comp)
{
    char pwd[100];
    char compar[] = "PWD";
    char empty[] = "..";
    int size = 0;

    if (val == 2) {
        if (separ.buffer[1] == 0 || separ.buffer[1] == " "){
            if (chdir(empty) == -1)
                write(1, "ERROR\n", 6);
            size++;
        }
        if (chdir(separ.buffer[1]) == -1 && size == 0){
            write(1, separ.buffer[1], my_strlen1(separ.buffer[1]));
            write(1, ": No such file or directory\n", 28);
            return (1);
            size++;
        }
        if (size > 0)
            modif_pwd(env);
    }
}
