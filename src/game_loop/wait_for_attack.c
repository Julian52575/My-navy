/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** wait_for_attack
*/
#include "../../includes/my_navy.h"

static void signals_handler(int signum)
{
    extern my navy;
    navy.enemy_attack[navy.enemy_attack_reference] = (signum / 12);
}

static double binary_to_map(void)
{
    extern my navy;
    short x_bin[3];
    short y_bin[3];
    for (int i = 0; i < 3; i++) {
        x_bin[i] = navy.enemy_attack[i];
        y_bin[i] = navy.enemy_attack[i + 3];
    }
    double x = (double)my_mini_binary_to_nbr(x_bin);
    double y = (double)my_mini_binary_to_nbr(y_bin);
    return x + (y / 10);
}

static void answer(void)
{
    extern my navy;
    double pos = binary_to_map();
    int x = pos;
    int y = (pos * 10) - (x * 10);
    my_putchar(x + 65);
    my_putchar(y + 49);
    if (fill_map_defence(x, y) == 1) {
        kill(navy.opponent_id, 12);
        navy.boat_left -= 1;
        write(1, ": hit\n", 6);
    } else {
        kill(navy.opponent_id, 10);
        write(1, ": missed\n", 9);
    }
    usleep(500);
    if (navy.boat_left <= 0)
        kill(navy.opponent_id, 12);
    else
        kill(navy.opponent_id, 10);
}

void wait_for_attack(void)
{
    extern my navy;
    write(1, "\nwaiting for enemy's attack...\n", 31);
    for (; navy.enemy_attack_reference < 6; navy.enemy_attack_reference++) {
        signal(10, signals_handler);
        signal(12, signals_handler);
        pause();
    }
    usleep(1000);
    navy.enemy_attack_reference = 0;
    answer();
    printf("\n");
    return;
}
