/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** put str
*/

#include "lib.h"

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (1);
}
