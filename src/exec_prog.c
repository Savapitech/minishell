/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** exec_prog
*/

#include "mysh.h"

void exec_prog(char **args,
    char **env,
    char **path)
{
    int status;
    pid_t pid = fork();
    char *exec_path;
    int exec_result;

    if (pid == 0) {
        for (int i = 0; path[i]; i++) {
            exec_path = my_strcat(path[i], "/");
            exec_path = my_strcat(exec_path, args[0]);
            exec_result = execve(exec_path, args, env);
        }
        if (exec_result == -1)
            my_printf("%s: Command not found.\n", args[0]);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        print_status(WIFSIGNALED(status));
    }
}
