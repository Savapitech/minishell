/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    #include <stdio.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
typedef struct {
    char **args;
    int count;
} ParsedArgs;
#endif /* !MYSH_H_ */
