/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** main
*/

#include "mysh.h"

int main(int argc, char **argv, char **env)
{
    char **path = get_path(env);
    char *buffer;
    size_t buf_size = 0;
    char **args;

    (void)argc;
    (void)argv;
    if (DEBUG_MODE == 1)
        for (int i = 0; path[i]; i++)
            my_printf("Path %d : %s\n", i, path[i]);
    while (1) {
        my_printf("$> ");
        getline(&buffer, &buf_size, stdin);
        args = parse_buffer(buffer);
        exec_prog(args, env, path);
    }
    free(buffer);
    free(path);
    return (0);
}
