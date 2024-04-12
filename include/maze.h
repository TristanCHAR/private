/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** maze
*/

#ifndef MAZE_H_
    #define MAZE_H_
    #include "my.h"
    #include "strtoarrfuncs.h"

void roomprinter(char **room);
void printer(maze_t maze);
int is_nbr(char *buff);
int nbcharcheck(char c);
void my_roomdup(room_t room, room_t *roomdup);
void nroom_set(room_t **room, char *buff);
int is_room(char *buff);
int is_tunnel(char *buff, maze_t *maze);
void ntunnel_set(tunnels_t **tunnels, char *buff);


#endif /* !MAZE_H_ */
