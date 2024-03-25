/*
** EPITECH PROJECT, 2024
** minishell [SSH: 45.88.180.12]
** File description:
** my_str_isalphanum
*/

#include "lib.h"

int my_str_isalphanum(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_char_isalpha(str[i]) == 0 && my_char_isnum(str[i]) == 0)
            return 0;
    }
    return 1;
}
