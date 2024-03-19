/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** setenv_unsetenv.c
*/

#include "mysh.h"

char **verif_setenv(char **env, char *key, char *value)
{
    if (my_char_isalpha(key[0]) == 0) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return env;
    }
    return my_setenv(env, key, value);
}
