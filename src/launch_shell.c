/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** launch_shell
*/

#include "mysh.h"

int handle_command(char **args, char ***env, char **path, char **env2)
{
    if (my_strcmp("exit", args[0]) == 0)
        exit(0);
    if (my_strcmp("cd", args[0]) == 0) {
        return execute_cd(args, env2);
    }
    if (my_strcmp("setenv", args[0]) == 0) {
        if (args[1] == NULL)
            return my_printenv(args, env2, path);
        *env = my_setenv(*env, args[1], args[2]);
        return 0;
    }
    if (my_strcmp("unsetenv", args[0]) == 0) {
        if (args[1] == NULL)
            return my_printf("unsetenv: Too few arguments.\n");
        *env = my_unsetenv(*env, args[1]);
        return 0;
    } else
        exec_prog(args, *env, path);
    return 0;
}

void launch_shell_tty(char **path, size_t buf_size, char **env)
{
    int getresult;
    char *buffer;
    char **args;

    while (1) {
        my_printf("$> ");
        getresult = getline(&buffer, &buf_size, stdin);
        if (my_str_isalpha(buffer) == 0 && my_str_isdigit(buffer) == 0)
            continue;
        if (getresult == -1)
            break;
        args = parse_buffer(buffer);
        handle_command(args, &env, path, env);
    }
    free(buffer);
}

void launch_shell_notty(char **path, size_t buf_size, char **env)
{
    int getresult;
    char *buffer;
    char **args;

    while (1) {
        getresult = getline(&buffer, &buf_size, stdin);
        if (getresult == -1)
            break;
        if (my_str_isalpha(buffer) == 0 && my_str_isdigit(buffer) == 0)
            continue;
        args = parse_buffer(buffer);
        handle_command(args, &env, path, env);
    }
    free(buffer);
}
