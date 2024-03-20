/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** my_strshift
*/

#include "lib.h"

char *my_strshift(char *str, int x)
{
    int i;
    int len = my_strlen(str);
    char *new_str = malloc((len + 1) * sizeof(char));

    for (i = 0; i < len - x; i++)
        new_str[i] = str[i + x];
    new_str[len - x] = '\0';
    return new_str;
}
