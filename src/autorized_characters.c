/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** autorized_characters
*/

int autorized_character(char c, int chara)
{
    if (chara == 1) {
        if ('A' <= c && c <= 'H')
            return 0;
    } else {
        if ('1' <= c && c <= '8')
            return 0;
    }
    return 84;
}
