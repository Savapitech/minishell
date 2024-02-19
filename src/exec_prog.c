/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** exec_prog
*/

#include "mysh.h"

void execute_program(parsed_args_t parsedArgs, char **env, char **path)
{
    int status;
    pid_t pid = fork();
    char *exec_path;
    int exec_result;

    parsedArgs.count -= 1;
    if (pid == 0) {
        for (int i = 0; path[i]; i++) {
            exec_path = my_strcat(path[i], "/");
            exec_path = my_strcat(exec_path, parsedArgs.args[0]);
            exec_result = execve(exec_path, parsedArgs.args, env);
        }
        if (exec_result == -1)
            my_puterr(my_strcat(my_strcat("Error: ", strerror(errno)), "\n"));
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    }
}
