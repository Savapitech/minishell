/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** get_env
*/

#include "mysh.h"

char *my_getenv(char *name, char **env)
{
    int i = 0;
    char *value = NULL;

    for (i = 0; env[i]; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0) {
            value = env[i];
            my_strshift(value, my_strlen(name) + 1);
            return value;
        }
    }
    return NULL;
}
