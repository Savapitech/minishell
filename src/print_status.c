/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean
** File description:
** print_status
*/

#include "mysh.h"

void print_status(int status)
{
    if (status != 0)
        write(2, "Segmentation fault\n", 19);
}
