/*
** EPITECH PROJECT, 2023
** PSU-navy
** File description:
** coord
*/

#include "../../includes/my_navy.h"

int *coords_to_int(char *coords)
{
    char x = coords[0];
    char y = coords[1];
    char ref_x[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char ref_y[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    for (int i = 0; ref_x[i]; i++) {
        if (ref_x[i] == x) {
            x = i;
        }
    }
    for (int i = 0; ref_y[i]; i++) {
        if (ref_y[i] == y) {
            y = i;
        }
    }
    int *result = malloc(sizeof(int) * 2);
    result[0] = x + 48;
    result[1] = y + 48;
    return (result);
}

char *int_to_coords(char *coords)
{
    char ref_x[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char ref_y[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char x = ref_x[coords[0] - '0'];
    char y = ref_y[coords[1] - '0'];
    char *result = malloc(sizeof(char) * (2 + 1) );
    result[0] = x;
    result[1] = y;
    result[2] = '\0';
    return (result);
}
