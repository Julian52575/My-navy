/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_board
*/
#include <unistd.h>

void my_put_array(char **array)
{
    for (int y = 0; array[y][0]; y++) {
        for (int x = 0; array[y][x]; x++) {
            write(1, &array[y][x], 1);
        }
        write(1, "\n", 1);
    }
}
