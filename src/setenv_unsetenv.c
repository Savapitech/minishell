/*
** EPITECH PROJECT, 2024
** shell
** File description:
** setenv_unsetenv.c
*/

#include "mysh.h"

char *concat_with_equal(char *key, char *value)
{
    int key_len = my_strlen(key);
    int value_len = my_strlen(value);
    char *result = malloc(key_len + value_len + 2);

    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < key_len; i++) {
        result[i] = key[i];
    }
    result[key_len] = '=';
    for (int i = 0; i < value_len; i++) {
        result[key_len + 1 + i] = value[i];
    }
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
    for (int j = 0; j < i; j++) {
        new_env[j] = env[j];
    }
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

void shift_env(char **env, int index)
{
    for (int j = index; env[j]; j++) {
        env[j] = env[j + 1];
    }
}

char **my_unsetenv(char **env, char *key)
{
    int i;
    char **new_env;

    i = find_key(env, key);
    if (i != -1) {
        free(env[i]);
        shift_env(env, i);
    }
    new_env = malloc(sizeof(char *) * (i + 1));
    for (int k = 0; k < i; k++) {
        new_env[k] = env[k];
    }
    new_env[i] = NULL;
    return new_env;
}
