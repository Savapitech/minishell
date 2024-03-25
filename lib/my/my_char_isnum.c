/*
** EPITECH PROJECT, 2024
** minishell [SSH: 45.88.180.12]
** File description:
** my_char_isnum
*/

#include "lib.h"

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
