/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** launch_shell
*/

#include "mysh.h"

void launch_shell_tty(
    char **path,
    size_t buf_size,
    char **env)
{
    int getresult;
    char *buffer;
    char **args;

    while (1) {
        my_printf("$> ");
        getresult = getline(&buffer, &buf_size, stdin);
        if (getresult == -1)
            break;
        args = parse_buffer(buffer);
        if (my_strcmp("exit", args[0]) == 0)
            exit(0);
        exec_prog(args, env, path);
    }
    free(buffer);
}

void launch_shell_notty(
    char **path,
    size_t buf_size,
    char **env)
{
    int getresult;
    char *buffer;
    char **args;

    while (1) {
        getresult = getline(&buffer, &buf_size, stdin);
        if (getresult == -1)
            break;
        args = parse_buffer(buffer);
        if (my_strcmp("exit", args[0]) == 0)
            exit(0);
        exec_prog(args, env, path);
    }
    free(buffer);
}
