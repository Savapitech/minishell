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
    size_t buf_size = 0;

    (void)argc;
    (void)argv;
    if (isatty(STDIN_FILENO))
        launch_shell_tty(path, buf_size, env);
    else
        launch_shell_notty(path, buf_size, env);
    free(path);
    return (0);
}
