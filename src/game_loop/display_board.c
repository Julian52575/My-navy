/*
** EPITECH PROJECT, 2023
** PSU-navy
** File description:
** display_board
*/

#include "../../includes/my_navy.h"

int my_put_board(char **board)
{
    int nbrline = 1;
    my_putstr(
    " |A B C D E F G H\n"
    "-+---------------\n");
    for (int i = 0; board[i][0]; i++) {
        my_putstr(int_to_string(nbrline));
        my_putchar('|');
        for (int k = 0; board[i][k]; k++) {
            my_putchar(board[i][k]);
            my_putchar(' ');
        }
        my_putchar('\n');
        nbrline++;
    }
    return (0);
}

void display_boards(void)
{
    extern my navy;
    write(1, "my positions:\n", 14);
    my_put_board(navy.board);
    write(1, "\nenemy's positions:\n", 20);
    my_put_board(navy.enemy_board);
}
