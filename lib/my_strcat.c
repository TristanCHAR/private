/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** test
*/

#include "../include/mystrlen.h"
#include <stdio.h>
#include <stdlib.h>

void my_reallocstr(char **str, size_t new_size, size_t old_size)
{
    char *new_str = malloc(new_size);

    for (size_t i = 0; i < old_size; i++) {
        new_str[i] = (*str)[i];
    }
    *str = new_str;
}

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int total_len = dest_len + src_len;

    my_reallocstr(&dest, (size_t)(total_len + 1), (size_t)(dest_len));
    for (int i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[total_len] = '\0';
    return dest;
}
