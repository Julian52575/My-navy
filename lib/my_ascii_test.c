/*
** EPITECH PROJECT, 2022
** my ascii test
** File description:
** return -1 si invalide, 1 si character, 2 si chiffre
*/

int my_ascii_test(char c)
{
    if (65 <= c && 90 <= c) {
        return 1;
    } else if (97 <= c && 122 <= c) {
        return 1;
    }
    if (48 <= c && c <= 57) {
        return 2;
    }

    return -84;
}
