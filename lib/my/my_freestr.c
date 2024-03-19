/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** my_freestr.c
*/

#include "lib.h"

void my_freestr(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
}
