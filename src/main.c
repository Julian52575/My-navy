/*
** EPITECH PROJECT, 2022
** main for navy
** File description:
** main
*/

#include "../includes/my_navy.h"

my navy = { 0 };

static int help_flag(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
        my_putstr("pid of the first player.\n\tnavy_positions:");
        my_putstr("file representing the positions of the ships.\n");
    }
    return (0);
}

static void init_navy(void)
{
    navy.board = create_board(8);
    navy.enemy_board = create_board(8);
    navy.enemy_attack = malloc(sizeof(int) * 9);
    navy.enemy_attack_reference = 0;
    navy.my_attack = malloc(sizeof(int) * 9);
    navy.boat_left = 14;
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;
    help_flag(av);
    init_navy();
    int error = (ac == 2 ? initialize_game(av) : join_game(av) );
    return error;
}
