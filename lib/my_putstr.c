/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <unistd.h>
#include "../include/putc.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
