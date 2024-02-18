/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** main
*/

#include "../includes/mysh.h"

ParsedArgs parse_args(int argc, char **argv)
{
    int i = 0;
    char **args = malloc(sizeof(char *) * (strlen(argv[1]) + 1));
    char *token = strtok(argv[1], " ");
    ParsedArgs parsedArgs;

    if (argc != 2) {
        write(2, "Usage: ./my_exec <command>\n", 26);
        exit(1);
    }
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    parsedArgs.args = args;
    parsedArgs.count = i;
    return parsedArgs;
}

void print_status(int status)
{
    if (status == 0)
        printf("Status: OK\n");
    else
        printf("Status: Segmentation fault\n");
}

void execute_program(ParsedArgs parsedArgs, char **env)
{
    int status;
    pid_t pid = fork();

    parsedArgs.count -= 1;
    printf("Program name: %s\n", parsedArgs.args[0]);
    printf("Nb args: %d\n", parsedArgs.count);
    printf("PID: %d\n", getpid());
    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        execve(parsedArgs.args[0], parsedArgs.args, env);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        printf("Program terminated.\n");
        print_status(WIFSIGNALED(status));
    }
}

int main(int argc, char **argv, char **env)
{
    ParsedArgs parsedArgs = parse_args(argc, argv);

    execute_program(parsedArgs, env);
    free(parsedArgs.args);
    return (0);
}