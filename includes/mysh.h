/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_
    #include "../lib/my/lib.h"
    #include <stdio.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>
    #define DEBUG_MODE 0
typedef struct {
    char **args;
    int count;
} parsed_args_t;
char **get_path(char **);
void get_path2(char **, char *);
void exec_prog(char **, char **, char **);
parsed_args_t parse_args(char **);
char **parse_buffer(char *);
void launch_shell_tty(char **, size_t, char **);
void launch_shell_notty(char **, size_t, char **);
void print_status(int);
#endif /* !MYSH_H_ */
