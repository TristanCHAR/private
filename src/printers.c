/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** printers
*/

#include "../include/my.h"

void roomprinter(char **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        my_putstr(room[i]);
        if (room[i + 1] == NULL)
            my_putstr("\n");
        else
            my_putstr(" ");
    }
}

void tunnelprinter(tunnels_t *tunnels)
{
    for (int i = 0; tunnels[i].arrtunnel != NULL; i++) {
        my_putstr(my_strcat(tunnels[i].arrtunnel[0], my_strcat("-",
            tunnels[i].arrtunnel[1])));
        my_putstr("\n");
    }
}

void roomarrprint(maze_t maze)
{
    for (int i = 0; maze.room[i].name != NULL; i++) {
        if (my_strcmp(maze.room[i].name, maze.start[0]) == 0)
            continue;
        if (my_strcmp(maze.room[i].name, maze.end[0]) == 0)
            continue;
        my_putstr(maze.room[i].name);
        my_putstr(" ");
        my_put_nbr(maze.room[i].x);
        my_putstr(" ");
        my_put_nbr(maze.room[i].y);
        my_putstr("\n");
    }
}

void printer(maze_t maze)
{
    my_putstr("#number_of_robots\n");
    my_put_nbr(maze.nbrobot);
    my_putstr("\n");
    my_putstr("#rooms\n");
    my_putstr("##start\n");
    roomprinter(maze.start);
    my_putstr("##end\n");
    roomprinter(maze.end);
    roomarrprint(maze);
    my_putstr("##tunnels\n");
    tunnelprinter(maze.tunnels);
}
