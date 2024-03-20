/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** get_path
*/

#include "mysh.h"

char **get_path(char **env)
{
    char *fpath;
    char **path;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            fpath = env[i];
            fpath = my_strshift(fpath, 5);
            path = malloc(sizeof(char *) * (my_strlen(fpath) + 1));
            get_path2(path, fpath);
            break;
        }
    }
    return path;
}

void get_path2(char **path, char *fpath)
{
    char *token;
    int pi = 0;

    token = strtok(fpath, ":");
    while (token != NULL) {
        path[pi] = token;
        pi++;
        token = strtok(NULL, ":");
    }
    path[pi] = NULL;
}
