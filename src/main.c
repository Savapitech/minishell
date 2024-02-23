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

    if (isatty(STDIN_FILENO)) {
        while (1) {
            my_printf("$> ");
            getline(&buffer, &buf_size, stdin);
            args = parse_buffer(buffer);
            exec_prog(args, env, path);
        }
    } else {
        getline(&buffer, &buf_size, stdin);
        args = parse_buffer(buffer);
        exec_prog(args, env, path);
    }
    free(buffer);
    free(path);
    return (0);
}
