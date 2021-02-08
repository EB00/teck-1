/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "include.h"

int other(ar_t separ, char **env)
{
    ar_t comp;
    int verif = 0;
    int val = -1;

    init_compar(&comp);
    for (int i = 0; separ.buffer[i] != 0; i++) {
        if (my_str_compare(comp.buffer[0], separ.buffer[i]) == 1) {
            exit_function(separ);
            return (1);
        }
        if (my_str_compare(comp.buffer[1], separ.buffer[i]) == 1) {
            if (verif == 0)
                verif = i + 1;
            val = 1;
        }
        if (my_str_compare(comp.buffer[2], separ.buffer[i]) == 1) {
            val = 2;
        }
    }
    other_fuction(separ, env, val, &comp);
    if (val == -1)
        return (0);
    return (1);
}

int acess(ar_t separ, ar_t array, int size, char *path)
{
    int size2 = (my_strlen(separ.buffer[0]) + my_strlen(array.buffer[size]) + 1);
    char *pathname = my_calloc(sizeof(char *) * size);
    int verif = 1;

    for (int compt = 0; array.buffer[size][compt] != '\0'; compt++) {
        pathname[compt] = array.buffer[size][compt];
        size2 = compt + 1;
    }
    pathname[size2] = '/';
    size2++;
    for (int leng = 0; separ.buffer[0][leng] != 0; leng++) {
        pathname[size2] = separ.buffer[0][leng];
        size2++;
    }
    verif = access(pathname, F_OK);
    if (verif == 0){
        if (array.cond > 0)
            for (int compt = 0; compt < my_strlen(pathname); compt++)
                path[compt] = pathname[compt];
        return (0);
    }
    return (- 1);
}

int son_father(char *path, char **env, ar_t separ)
{
    int stat;

    separ.cond = 0;
    separ.pid = fork();
    if (separ.pid < 0)
        exit (84);
    if (separ.pid != 0) {
        getpid();
        waitpid(separ.pid, &stat, 0);
    } else if (separ.pid == 0)
        if (execve(path, separ.buffer, env) == -1) {
            return (84);
        }
    return (0);
}

int function(ar_t separ, ar_t array, char **env)
{
    char *path = NULL;
    int verif = 1;
    int size = 0;
    int recup = 1;

    array.cond = 0;
    while (array.buffer[size] != 0 && verif != 0) {
        verif = acess(separ, array, size, path);
        if (array.buffer[0] == "\n")
            return (0);
        if (verif == 0) {
            array.cond++;
            path = my_calloc(sizeof(char *) *
                             (my_strlen(separ.buffer[0]) +
                              my_strlen(array.buffer[size]) + 1));
            recup = acess(separ, array, size, path);
        }
        size++;
    }
    if (recup == 0)
        son_father(path, env, separ);
    else {
        write(1, separ.buffer[0], my_strlen2(separ.buffer[0]));
        write(1, ": Command not found.\n", 21);
    }
    return (verif);
}

int main(int ac, char **av, char **env)
{
    char *buffer = NULL;
    size_t bufsize = 2;
    ar_t array;
    ar_t separ;
    char *path;
    char val = ' ';

    path = cut_env(env);
    arrays(ac, path, &array);
    while (1) {
        print_user();
        if (getline(&buffer, &bufsize, stdin) == -1) {
            write(1, "\n", 1);
            return (0);
        }
        buffer[my_strlen(buffer) - 1] = '\0';
        separ.buffer = new_array(buffer, &separ, val);
        if (other(separ, env) == 0)
            function(separ, array, env);
    }
    return (0);
}
