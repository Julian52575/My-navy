/*
** EPITECH PROJECT, 2022
** my str to word array
** File description:
** Flat str becomes huge array
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void my_put_array(char **array, char del);

char **my_str_to_word_array(char *str)
{
    char **array = malloc( sizeof(char *) * my_strlen(str) + 1);
    int y = 0;
    int x = 0;
    while (str[0]) {
        while (str[0] == ' ' || str[0] == '\n') ++str;
        array[y] = malloc( sizeof(char) * (my_strlen(str) + 1) );
        while (str[0] && (str[0] != ' ' && str[0] != '\n') ) {
            array[y][x++] = str[0];
            str++;
        }
        array[y][x] = '\0';
        x = 0;
        y++;
    }
    array[y] = malloc(sizeof(char) * 1);
    array[y][0] = '\0';
    return array;
}
