/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_mini_binary_to_nbr
*/

short my_mini_binary_to_nbr(short *binary)
{
    int dec = 0;
    if (binary[0] == 1)
        dec += 4;
    for (int i = 1; i < 3; i++) {
        if (binary[i] == 1)
            dec += (4 / (2 * i) );
    }
    return dec;
}
