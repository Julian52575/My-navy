/*
** EPITECH PROJECT, 2022
** Game loop
** File description:
** THE GAME
*/
#include "../../includes/my_navy.h"

//do the game_loop and returns 0
void game_loop(void)
{
    extern my navy;
    while (navy.boat_left > 0 && navy.result < 24) {
        navy.result = 0;
        display_boards();
        if (navy.turn == true)
            do_attack();
        else
            wait_for_attack();
        navy.turn = !navy.turn;
        usleep(500);
    }
    display_boards();
    if (navy.result == 24) {
        write(1, "\nI won\n", 7);
    } else {
        write(1, "\nEnemy won\n", 11);
    }
    return;
}
