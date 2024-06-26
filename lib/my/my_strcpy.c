/*
** EPITECH PROJECT, 2023
** CPoolDay07
** File description:
** ./my_strcpy.c
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
