/*
** EPITECH PROJECT, 2024
** strtoarr
** File description:
** strtoarr
*/

#include "../include/strtoarrfuncs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charstr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

static int word_len(char *str, char *sep)
{
    int wlen = 0;

    for (str = str; *str != '\0' && !charstr(sep, *str); str++) {
        wlen++;
    }
    return wlen;
}

char **strtoarr(char *str, char *sep)
{
    char **arr = NULL;
    int n = 0;
    int arrlen = 0;

    for (str = str; *str != '\0'; str++) {
        n = word_len(str, sep);
        if (n == 0)
            continue;
        arr = my_realloc(arr, sizeof(char *) * arrlen,
            sizeof(char *) * (arrlen + 1));
        arr[arrlen] = my_strndup(str, n);
        arrlen++;
        str += n - 1;
    }
    arr = my_realloc(arr, sizeof(char *) * arrlen,
        sizeof(char *) * (arrlen + 1));
    arr[arrlen] = NULL;
    return arr;
}
