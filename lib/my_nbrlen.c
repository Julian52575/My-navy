/*
** EPITECH PROJECT, 2022
** my nbrlen
** File description:
** nbr len
*/

#include "lib.h"

int my_nbrlen(int nbr)
{
    int i = 0;
    for (;nbr > 0; i++) {
        nbr = nbr / 10;
    }
    return (i);
}
