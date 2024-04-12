/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function that return the length of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
