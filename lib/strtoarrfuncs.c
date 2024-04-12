/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** strtoarrfuncs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++) {
        dest[i] = src[i];
    }
    return *dest;
}

void *my_realloc(void *ptr, size_t old, size_t size)
{
    void *nptr = malloc(size);

    my_strncpy(nptr, ptr, old);
    free(ptr);
    return nptr;
}

char *my_strndup(const char *s, size_t n)
{
    char *dup = malloc(sizeof(char) * (n + 1));

    if (dup == NULL) {
        return NULL;
    }
    my_strncpy(dup, s, n);
    dup[n] = '\0';
    return dup;
}
