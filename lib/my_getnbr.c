/*
** EPITECH PROJECT, 2023
** C pool day04 task05
** File description:
** task05
*/

#include "../include/mystrlen.h"

int is_neg(char const *str, int len)
{
    int cpt_minus = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '-') {
            cpt_minus++;
        }
    }
    return cpt_minus % 2 != 0;
}

int nb_sign(char const *str, int len)
{
    int cpt = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '-' || str[i] == '+') {
            cpt++;
        }
    }
    return cpt;
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    long long n = 0;

    for (int i = 0; i < len; i++) {
        if ((i > 0 || len > 1) && str[i] >= '0' && str[i] <= '9') {
            n = n * 10;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            n = n + (str[i] - '0');
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
            break;
    }
    if (is_neg(str, len))
        n = -n;
    if (len - nb_sign(str, len) > 11 || n > 2147483647 || n < -2147483648)
        return 0;
    return (int)n;
}
