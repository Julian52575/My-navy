/*
** EPITECH PROJECT, 2023
** PSU-navy
** File description:
** lib
*/

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int my_strlen(char *str);
int my_str_to_int(char *str);
char *open_file(char *file_path);
void my_putnbr(int nb);
void my_putchar(char c);
int my_ascii_test(char c);
void my_fill_str(char *str, char c, int end);
void my_put_array(char **array);
int my_putstr(char *str);
int my_nbrlen(int nbr);
char* int_to_string(int nbr);
short *my_mini_nbr_to_binary(int number);
short my_mini_binary_to_nbr(short *binary);
