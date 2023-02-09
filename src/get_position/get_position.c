/*
** EPITECH PROJECT, 2022
** Test pos
** File description:
** Are the positiions valid ? Return 84 if not
*/

#include "../../includes/my_navy.h"

static int valid_txt(char *txt)
{
    if (!txt[0]) return 84;
    if (my_strlen(txt) < 31) return 84;
    if ((txt[7] + txt[15] + txt[23] + txt[31]) != ('\n' * 4)) return 84;
    for (int i = 0; i < 4; i++) {
        if (txt[0 + (8 * i)] != (char)(50 + i) )
            return 84;
        if (txt[1 + (8 * i)] != ':' || txt[4 + (8 * i)] != ':')
            return 84;
        if (txt[7 + (8 * i)] != '\n')
            return 84;
        if ( autorized_character(txt[2 + (8 * i)], 1) == 84)
            return 84;
        if ( autorized_character(txt[5 + (8 * i)], 1) == 84)
            return 84;
        if ( autorized_character(txt[3 + (8 * i)], 0) == 84)
            return 84;
        if ( autorized_character(txt[6 + (8 * i)], 0) == 84)
            return 84;
    }
    return 0;
}

static int valid_boats(char *txt)
{
    for (int i = 0; i < 4; i++) {
        if ((txt[2 + (8 * i)] != txt[5 + (8 * i)])
        && (txt[3 + (8 * i)] != txt[6 + (8 * i)]) )
            return 84;
        if (txt[6 + (8 * i)] - txt[3 + (8 * i)] > txt[0 + (8 * i) ] - 49)
            return 84;
    }
    return 0;
}

static int add_position(char *txt, int i)
{
    extern my navy;
    int x = txt[3 + (8 * i) - 1] - 65;
    int y = txt[4 + (8 * i) - 1] - 48;
    for (int size = 0; size < txt[0 + (8 * i)] - 48; size++) {
        int h = 0;
        int v = 0;
        if ( (txt[2 + (8 * i)] != txt[5 + (8 * i)]) )
            h = 1;
        else
            v = 1;
        if (navy.board[y + (v * size) - 1][x + (h * size)] != '.')
            return 84;
        navy.board[y + (v * size) - 1][x + (h * size)] = txt[0 + (8 * i)];
    }
    return 0;
}

//add the boat position inside the navy structure or returns 84;
int get_position(char *txt)
{
    if (valid_txt(txt) == 84) return 84;
    if (valid_boats(txt) == 84) return 84;
    int error = 0;
    for (int i = 0; i < 4 && error == 0; i++) {
        error = add_position(txt, i);
    }
    if (error == 84)
        return 84;
    return 0;
}
