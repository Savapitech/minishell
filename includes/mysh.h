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
void launch_shell_tty(char **, size_t, char **, char *);
void launch_shell_notty(char **, size_t, char **);
void print_status(int);
char **my_setenv(char **, char *, char *);
char **my_unsetenv(char **, char *);
int execute_cd(char **, char **);
char *my_getenv(char *, char **);
int my_printenv(char **, char **, char **);
int execute_env(char **);
char **verif_setenv(char **, char *, char *);
#endif /* !MYSH_H_ */
