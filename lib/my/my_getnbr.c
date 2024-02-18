/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** 4
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10 + (str[i] - '0');
        } else {
            break;
        }
    }
    return nbr * sign;
}
