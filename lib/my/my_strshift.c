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
    int len;

    len = my_strlen(str);
    for (i = 0; i < len - x; i++)
        str[i] = str[i + x];
    str[len - x] = '\0';
    return str;
}
