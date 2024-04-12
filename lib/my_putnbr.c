/*
** EPITECH PROJECT, 2023
** myputnbr
** File description:
** a function that prints the number given as parameter
*/

#include <unistd.h>
#include "../include/putc.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb < 10)
        my_putchar(nb + '0');
    else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}
