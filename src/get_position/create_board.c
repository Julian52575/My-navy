/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_board
*/

#include "../../includes/my_navy.h"
void my_fill_str(char *str, char c, int end);

char **create_board(int lenght)
{
    char **board = malloc(sizeof(char *) * (lenght + 1) );
    for (int y = 0; y <= lenght; y++) {
        board[y] = malloc(sizeof(char) * (lenght + 1) );
        board[y][lenght] = '\0';
        my_fill_str(board[y], '.', lenght);
    }
    board[lenght][0] = '\0';

    return board;
}
