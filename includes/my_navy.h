/*
** EPITECH PROJECT, 2022
** My navy.h
** File description:
** header for pushswap
*/
#pragma once

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/lib.h"

typedef struct my_navy {
    int SIG1_buffer;
    int SIG2_buffer;
    pid_t id;
    int opponent_id;
    int turn;
    char **board;
    char **enemy_board;
    short *my_attack;
    short *enemy_attack;
    int enemy_attack_reference;
    int was_succesful;
    int boat_left;
    int result;
} my;

char **create_board(int lenght);
void my_sigaction(struct sigaction *sig_buffer1,
struct sigaction *sig_buffer2);

int get_position(char *txt);
int autorized_character(char c, int chara);

int initialize_game(char **av);
int join_game(char **av);

void game_loop(void);
void do_attack(void);
void wait_for_attack(void);

int fill_map_defence(int x, int y);
void fill_map_attack(char *position);

int my_put_board(char **board);
void display_boards(void);
