/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** env_cmd
*/

#include "mysh.h"

int execute_env(char **env)
{
    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
    return 0;
}
