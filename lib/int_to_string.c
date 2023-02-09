/*
** EPITECH PROJECT, 2022
** MUL-myhunter
** File description:
** int_to_string
*/

#include "lib.h"

char* int_to_string(int nbr)
{
    if (nbr == 0)
        return ("0");
    int size = my_nbrlen(nbr);
    int mul = 1;
    for (int a = 1; a != size; a++) {
        mul *= 10;
    }
    char* str = malloc(sizeof(char) * size + 1);
    int i = 0;

    while (i != size) {
        str[i] = ((nbr / mul) % 10) + 48;
        mul /= 10;
        i++;
    }
    str[i] = '\0';
    return (str);
}
