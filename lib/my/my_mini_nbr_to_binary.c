/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_nbr_to_binary
*/
#include <stdlib.h>
#include <stdio.h>

short *my_mini_nbr_to_binary(int number)
{
    if (number >= 8)
        return NULL;
    short *binary = malloc(sizeof(short) * 3);
    int i = 2;
    while (number > 0 && i >= 0) {
        binary[i] = number % 2;
        number /= 2;
        i--;
    }
    return binary;
}
