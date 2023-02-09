/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_sigaction
*/
#include "../includes/my_navy.h"

//combines sigaction 10, 12 and pause in a single function
void my_sigaction(struct sigaction *sig_buffer1,
struct sigaction *sig_buffer2)
{
    sigaction(10, sig_buffer1, NULL);
    sigaction(12, sig_buffer2, NULL);
    pause();
}
