/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** room_handler
*/

#include "../include/my.h"
#include "../include/strtoarrfuncs.h"

int fnbcharcheck(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

void my_roomdup(room_t room, room_t *roomdup)
{
    roomdup->name = my_strndup(room.name, my_strlen(room.name));
    roomdup->x = room.x;
    roomdup->y = room.y;
}

void nroom_set(room_t **room, char *buff)
{
    static int nbroom = 0;
    char **arrbuff = NULL;
    room_t *nroom = malloc(sizeof(room_t) * (nbroom + 2));

    for (int i = 0; i < nbroom; i++) {
        nroom[i].name = my_strndup((*room)[i].name,
            my_strlen((*room)[i].name));
        nroom[i].x = (*room)[i].x;
        nroom[i].y = (*room)[i].y;
    }
    arrbuff = strtoarr(buff, " ");
    nroom[nbroom].name = my_strndup(arrbuff[0], my_strlen(arrbuff[0]));
    nroom[nbroom].x = my_getnbr(arrbuff[1]);
    nroom[nbroom].y = my_getnbr(arrbuff[2]);
    nroom[nbroom + 1].name = NULL;
    free(*room);
    *room = nroom;
    free_array(&arrbuff);
    nbroom++;
}

int is_room(char *buff)
{
    char **arrbuff = strtoarr(buff, " ");

    if (my_arrlen(arrbuff) < 3)
        return 0;
    for (int u = 0; (arrbuff[1][u] != '\0' || arrbuff[1][u] != '#') &&
        u != my_strlen(arrbuff[1]); u++)
        if (fnbcharcheck(arrbuff[1][u]) != 1)
            return 0;
    for (int u = 0; (arrbuff[2][u] != '\0' || arrbuff[2][u] != '#') &&
        u != my_strlen(arrbuff[2]); u++)
        if (fnbcharcheck(arrbuff[2][u]) != 1)
            return 0;
    return 1;
}
