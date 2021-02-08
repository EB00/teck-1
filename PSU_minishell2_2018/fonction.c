/*
** EPITECH PROJECT, 2019
** minishel
** File description:
** fonction.c
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "include.h"

int my_strlen1(const char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return (i);
}


void print_user(void)
{
    char pwd[100];
    int size = 0;
    
    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        write(1, "[Phoenix@", 8);
        write(1, pwd, my_strlen1(pwd));
        write(1, "]$ >", 4);
    }
}

char *cut_env(char **env)
{
    char *path;
    int o = 0;

    for (int i = 0; env[i] != 0; i++){
        if (env[i][0] =='P' && env[i][1] == 'A' &&
            env[i][2] == 'T') {
            path = my_calloc(sizeof(char *) * (my_strlen(env[i]) + 1));
            for (int x = 5; x != my_strlen(env[i]); x++) {
                path[o] = env[i][x];
                o++;
            }
            path[o + 1] = '\0';
        }
    }
    return (path);
}

char *my_calloc(int size)
{
    char *result = malloc(size);

    if (result == NULL)
        return (NULL);

    for (int j = 0; j != size; j++)
        result[j] = '\0';
    return (result);
}
