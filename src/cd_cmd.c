/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** cd_cmd
*/

#include "mysh.h"

int execute_cd(char **args, char **env)
{
    int status;
    char *path = args[1];

    if (path == NULL || my_strcmp(path, "~") == 0) {
        path = my_getenv("HOME", env);
        printf("path %s\n", path);
        if (path == NULL)
            path = "/";
    }
    status = chdir(path);
    if (status == -1) {
        write(2, path, my_strlen(path));
        write(2, ": No such file or directory.\n", 29);
    }
    return 0;
}
