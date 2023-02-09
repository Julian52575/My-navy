/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** fill_map, fill both map with the ongoing attack
*/
#include "../../includes/my_navy.h"

int fill_map_defence(int x, int y)
{
    extern my navy;
    if (navy.board[y][x] != '.' && navy.board[y][x] != 'o') {
        navy.board[y][x] = 'x';
        return 1;
    } else {
        navy.board[y][x] = 'o';
        return 0;
    }
}

void fill_map_attack(char *position)
{
    extern my navy;
    if (navy.was_succesful == 1)
        navy.enemy_board[position[1] - 49][position[0] - 65] = 'x';
    else
        navy.enemy_board[position[1] - 49][position[0] - 65] = 'o';
    return;
}
