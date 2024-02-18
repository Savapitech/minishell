/*
** EPITECH PROJECT, 2024
** B-PSU-200-REN-2-1-minishell1-savinien.petitjean [SSH: 45.88.180.12]
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int nb)
{
    int i = 0;

    if (nb == 0)
        return 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && i < nb - 1) {
        i++;
    }
    return s1[i] - s2[i];
}
