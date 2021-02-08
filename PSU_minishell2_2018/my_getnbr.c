/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** task05, i can do it
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int i;
    int recup = 0;
    int final = 0;
    int negatif = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            negatif++;
            i++;
        } else if (str[i] > '0' && str[i] < '9') {
            recup  = str[i] - 48;
            final = final * 10 + recup;
            i++;
        } else if (str[i] < '0' && str[i] != '-' || str[i] > '9')
            i++;
    }
    if (negatif > 0)
        final = final * -1;
    return (final);
}
