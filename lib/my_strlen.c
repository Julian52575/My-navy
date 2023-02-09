/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** you know it
*/

int my_strlen(char *str)
{
    if (str[0]) return my_strlen(++str) + 1;
    return 0;
}
