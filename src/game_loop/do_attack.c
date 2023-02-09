/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** do_attack
*/
#include "../../includes/my_navy.h"

static int valid_buffer(char *buffer)
{
    extern my navy;
    if ( autorized_character(buffer[0], 1) == 84)
        return 84;
    if ( autorized_character(buffer[1], 0) == 84)
        return 84;
    if ( buffer[2] != '\n')
        return 84;
    if (navy.enemy_board[buffer[1] - 49][buffer[0] - 65] != '.')
        return 84;
    return 0;
}

static char *get_attack_imput(void)
{
    int a = 0;
    char *buffer = NULL;
    size_t len = 0;
    while (a == 0) {
        write(1, "\nattack: ", 9);
        getline(&buffer, &len, stdin);
        if (valid_buffer(buffer) == 84) {
            buffer[0] = '0';
            write(1, "wrong position", 14);
        } else {
            a = 1;
        }
    }
    return buffer;
}

static void signals_handler(int signum)
{
    extern my navy;
    if (!navy.was_succesful)
        navy.was_succesful = signum / 12;
    navy.result += signum;
}

static void send_attack(short *x, short *y)
{
    extern my navy;
    usleep(200);
    kill(navy.opponent_id, 10 + (x[0] * 2) );
    usleep(201);
    kill(navy.opponent_id, 10 + (x[1] * 2) );
    usleep(201);
    kill(navy.opponent_id, 10 + (x[2] * 2) );
    usleep(201);
    kill(navy.opponent_id, 10 + (y[0] * 2) );
    usleep(201);
    kill(navy.opponent_id, 10 + (y[1] * 2) );
    usleep(201);
    kill(navy.opponent_id, 10 + (y[2] * 2) );
    for (int i = 0; i < 2; i++) {
        signal(10, signals_handler);
        signal(12, signals_handler);
        pause();
    }
}

void do_attack(void)
{

    extern my navy;
    char *buff = get_attack_imput();
    short *x = my_mini_nbr_to_binary(buff[0] - 65);
    short *y = my_mini_nbr_to_binary(buff[1] - 49);
    send_attack(x, y);
    fill_map_attack(buff);
    write(1, buff, 2);
    if (navy.was_succesful == 0)
        write(1, ": missed\n\n", 11);
    else
        write(1, ": hit\n\n", 7);
    free(x);
    free(y);
}
