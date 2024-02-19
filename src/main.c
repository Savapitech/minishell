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
    parsed_args_t parsedArgs = parse_args(argv);

    if (DEBUG_MODE == 1)
        for (int i = 0; path[i]; i++)
            my_printf("Path %d : %s\n", i, path[i]);
    execute_program(parsedArgs, env, path);
    free(parsedArgs.args);
    free(path);
    return (0);
}
