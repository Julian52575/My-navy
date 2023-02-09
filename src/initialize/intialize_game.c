/*
** EPITECH PROJECT, 2022
** Initialize_game
** File description:
** initialize the game (1st processus)
*/

#include "../../includes/my_navy.h"

static void sig2_handler(int signum, siginfo_t *info, void *ucontext)
{
    extern my navy;
    ++navy.SIG2_buffer;
    if (navy.opponent_id != 0 && (navy.opponent_id != info->si_pid) ) {
        navy.SIG1_buffer = 0;
        navy.SIG2_buffer = 0;
    }
    navy.opponent_id = info->si_pid;
    kill(navy.opponent_id, 10);
}

static void sig1_handler(int signum, siginfo_t *info, void *ucontext)
{
    extern my navy;
    ++navy.SIG1_buffer;
    if (navy.opponent_id != info->si_pid) {
        navy.SIG1_buffer = 0;
        navy.SIG2_buffer = 0;
    }
    navy.opponent_id = info->si_pid;
    kill(navy.opponent_id, 12);
}

static int initialize_navy(struct sigaction *sig1, struct sigaction *sig2
, char *file)
{
    extern my navy;
    navy.turn = true;
    navy.id = getpid();
    sig1->sa_flags = SA_SIGINFO;
    sig1->sa_sigaction = &sig1_handler;
    sig2->sa_flags = SA_SIGINFO;
    sig2->sa_sigaction = &sig2_handler;
    char *txt = open_file(file);
    if (!txt) return 84;
    if (get_position(txt) == 84) return 84;
    free(txt);
    return 0;
}

//  ./navy pos1
int initialize_game(char **av)
{
    extern my navy;
    struct sigaction sig1 = {0};
    struct sigaction sig2 = {0};
    if (initialize_navy(&sig1, &sig2, av[1]) == 84) return 84;
    write(1, "my_pid: ", 8);
    my_putnbr(navy.id);
    write(1, "\nwaiting for enemy connection...\n", 34);
    while (!navy.SIG1_buffer || !navy.SIG2_buffer) {
        my_sigaction(&sig1, &sig2);
    }
    navy.SIG1_buffer = 0;
    navy.SIG2_buffer = 0;
    write(1, "\nenemy connected\n\n", 18);
    game_loop();
    return 0;
}
