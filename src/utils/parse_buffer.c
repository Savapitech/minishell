/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** parse_buffer
*/

#include "mysh.h"

char **parse_buffer(char *buffer)
{
    char **args = malloc(sizeof(char *) * 1024);
    char *token;
    int i = 0;

    token = strtok(buffer, " \n");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
    return args;
}
