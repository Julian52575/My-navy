/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** my_fill_str
*/

void my_fill_str(char *str, char c, int end)
{
    for (int i = 0; i < end; i++) {
        str[i] = c;
    }
}
