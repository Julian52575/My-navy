/*
** EPITECH PROJECT, 2022
** put nbr
** File description:
** print a int
*/
void my_putchar(char c);

int my_putnbr(int nb)
{
    if (nb < 10)
        my_putchar(nb + 48);
    else {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (nb);
}
