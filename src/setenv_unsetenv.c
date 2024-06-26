/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** setenv_unsetenv.c
*/

#include "mysh.h"

char *concat_with_equal(char *key, char *value)
{
    int key_len = my_strlen(key);
    int value_len;
    char *result;

    if (value == NULL)
        value = "";
    value_len = my_strlen(value);
    result = malloc(key_len + value_len + 2);
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < key_len; i++)
        result[i] = key[i];
    result[key_len] = '=';
    for (int i = 0; i < value_len; i++)
        result[key_len + 1 + i] = value[i];
    result[key_len + value_len + 1] = '\0';
    return result;
}

char **my_setenv(char **env, char *key, char *value)
{
    int i;
    char *new_entry = concat_with_equal(key, value);
    char **new_env;

    for (i = 0; env[i]; i++) {
        if (my_strncmp(env[i], key, my_strlen(key)) == 0
        && env[i][my_strlen(key)] == '=') {
            free(env[i]);
            env[i] = new_entry;
            return env;
        }
    }
    new_env = malloc(sizeof(char *) * (i + 2));
    for (int j = 0; j < i; j++)
        new_env[j] = env[j];
    new_env[i] = new_entry;
    new_env[i + 1] = NULL;
    return new_env;
}

int find_key(char **env, char *key)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], key, my_strlen(key))
        == 0 && env[i][my_strlen(key)] == '=') {
            return i;
        }
    }
    return -1;
}

int count_env(char **env)
{
    int count = 0;

    while (env[count])
        count++;
    return count;
}

char **my_unsetenv(char **env, char *key)
{
    int i = 0;
    int j = 0;
    int total = count_env(env);
    char **new_env = malloc(sizeof(char *) * (total + 1));

    i = find_key(env, key);
    if (i == -1)
        return env;
    for (int k = 0; k < total; k++) {
        if (k != i) {
            new_env[j] = env[k];
            j++;
        }
    }
    new_env[j] = NULL;
    return new_env;
}
