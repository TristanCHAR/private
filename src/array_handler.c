/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** array_handler
*/

#include "../include/my.h"

int nbcharcheck(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int is_nbr(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (nbcharcheck(buff[i]) == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

int my_arrlen(char **arr)
{
    int nbel = 0;

    for (nbel = nbel; arr[nbel] != NULL; nbel++);
    return nbel;
}

char **my_arrdup(char **arr)
{
    int i = 0;
    char **narr = malloc(sizeof(char *) * (my_arrlen(arr) + 1));

    for (arr = arr; *arr != NULL; arr++) {
        narr[i] = malloc(sizeof(char) * my_strlen(*arr));
        narr[i] = *arr;
        i++;
    }
    narr[i] = NULL;
    return narr;
}

void free_array(char ***array)
{
    for (int j = 0; (*array)[j] != NULL; j++)
        free((*array)[j]);
    free(*array);
}
