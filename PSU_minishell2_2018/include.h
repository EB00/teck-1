/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** include.h
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifndef _INCLUDE_H_
#define _INCLUDE_H_

typedef struct array_t {
    char **buffer;
    int cond;
    int error;
    pid_t pid;
}ar_t;

void exit_function(ar_t separ);
int arrays(int ac, char *av, ar_t *array);
int compt_space(char *str);
int my_strlen(char *str);
char **new_array(char *av, ar_t *array, char val);
int my_str_compare(char *str, char *compare);
void print_user(void);
int my_strlen1(const char *str);
char *cut_env(char **env);
int init_compar(ar_t *comp);
int other_fuction(ar_t separ, char **env, int val, ar_t *comp);
int my_str_compare1(char *str, char *compare);
int my_strlen2(char *str);
char *my_calloc(int size);
int my_getnbr(char const *str);
#endif
