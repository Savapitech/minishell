/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** setenv_unsetenv2.c
*/

#include "mysh.h"

char **verif_setenv(char **env, char *key, char *value)
{
    if (my_char_isalpha(key[0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return env;
    }
    if (my_str_isalphanum(key) == 0) {
        write(2, "setenv: Variable name must contain alphanumeric", 47);
        write(2, " characters.\n", 13);
        return env;
    }
    return my_setenv(env, key, value);
}
