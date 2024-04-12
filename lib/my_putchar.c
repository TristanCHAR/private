/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** my_putchar perso
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
