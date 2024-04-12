/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** tunnel_handler
*/

#include "../include/my.h"

int is_tunnel(char *buff, maze_t *maze)
{
    int index = 0;
    char **bufft = NULL;

    if (my_arrlen(strtoarr(buff, "-")) != 2)
        return 0;
    bufft = strtoarr(buff, "-");
    for (int i = 0; maze->room[i].name != NULL; i++) {
        if (my_strcmp(maze->room[i].name, bufft[0]) == 0)
            index++;
        if (my_strcmp(maze->room[i].name, bufft[1]) == 0)
            index++;
    }
    if (index == 2) {
        return 1;
    } else {
        return 0;
    }
}

void ntunnel_set(tunnels_t **tunnels, char *buff)
{
    static int nbt = 0;
    tunnels_t *nt = malloc(sizeof(tunnels_t) * (nbt + 2));

    for (int i = 0; i < nbt; i++) {
        nt[i].arrtunnel = my_arrdup((*tunnels)[i].arrtunnel);
    }
    nt[nbt].arrtunnel = strtoarr(buff, "-");
    nt[nbt + 1].arrtunnel = NULL;
    free(*tunnels);
    *tunnels = nt;
    nbt++;
}
