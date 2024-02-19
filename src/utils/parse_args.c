/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** parse_args
*/

#include "mysh.h"

parsed_args_t parse_args(char **argv)
{
    int i = 0;
    char **args = malloc(sizeof(char *) * (strlen(argv[1]) + 1));
    char *token = strtok(argv[1], " ");
    parsed_args_t parsedArgs;

    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    parsedArgs.args = args;
    parsedArgs.count = i;
    return parsedArgs;
}
