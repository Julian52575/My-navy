/*
** EPITECH PROJECT, 2022
** Join game
** File description:
** join the game created by processus 1 (2nd processus)
*/

#include "../../includes/my_navy.h"

static void sig2_handler(int signum, siginfo_t *info, void *ucontext)
{
    extern my navy;
    ++navy.SIG2_buffer;
}

static void sig1_handler(int signum, siginfo_t *info, void *ucontext)
{
    extern my navy;
    ++navy.SIG1_buffer;
    kill(navy.opponent_id, 10);
}

static int initialize_navy(struct sigaction *sig1, struct sigaction *sig2
, char **av)
{
    extern my navy;
    char *txt = open_file(av[2]);
    if (!txt) return 84;
    if (get_position(txt) == 84) return 84;
    for (int i = 0; i < my_strlen(av[1]); i++) {
        if (my_ascii_test(av[1][0]) != 2) return 84;
    }
    navy.turn = false;
    navy.opponent_id = my_str_to_int(av[1]);
    navy.id = getpid();
    sig1->sa_flags = SA_SIGINFO;
    sig1->sa_sigaction = sig1_handler;
    sig2->sa_flags = SA_SIGINFO;
    sig2->sa_sigaction = sig2_handler;
    free(txt);
    return 0;
}

//   ./navy 4242 pos2
int join_game(char **av)
{
    extern my navy;
    struct sigaction sig1 = {0};
    struct sigaction sig2 = {0};
    if (initialize_navy(&sig1, &sig2, av) == 84) return 84;
    write(1, "my_pid: ", 8);
    my_putnbr(navy.id);
    write(1, "\n", 1);
    kill(navy.opponent_id, 12);
    while (!navy.SIG1_buffer || !navy.SIG2_buffer)
        my_sigaction(&sig1, &sig2);
    navy.SIG1_buffer = 0;
    navy.SIG2_buffer = 0;
    write(1, "successfully connected\n", 23);
    game_loop();
    return 0;
}
