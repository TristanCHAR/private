/*
** EPITECH PROJECT, 2024
** A_Maze_D
** File description:
** main
*/

#include "../include/mystrlen.h"
#include "../include/strtoarrfuncs.h"
#include "../include/maze.h"
#include "../include/my.h"


int is_command(char *buff, char *command)
{
    if (buff[0] == '#' && buff[1] == '#' && buff[2] != '#') {
        if (my_strcmp((buff + 2), command) == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

void bsn_remover(char **buffer)
{
    if ((*buffer)[my_strlen(*buffer) - 1] == '\n')
        (*buffer)[my_strlen(*buffer) - 1] = '\0';
}

static void command_check(char *buff, int *nbline, size_t buffsize,
    maze_t *maze)
{
    char *buffer = NULL;
    static int iss = 0;
    static int ise = 0;

    if (is_command(buff, "start") == 1 && iss == 0) {
        getline(&buffer, &buffsize, stdin);
        bsn_remover(&buffer);
        (*nbline)++;
        maze->start = my_arrdup(strtoarr(buffer, " "));
        nroom_set(&maze->room, buffer);
        iss = 1;
    }
    if (is_command(buff, "end") == 1 && ise == 0) {
        getline(&buffer, &buffsize, stdin);
        bsn_remover(&buffer);
        (*nbline)++;
        maze->end = my_arrdup(strtoarr(buffer, " "));
        nroom_set(&maze->room, buffer);
        ise = 1;
    }
}

static int struct_filler(maze_t *maze, char *buff, size_t buffsize,
    int *nbline)
{
    static int isnb = 0;

    if (buff[my_strlen(buff) - 1] == '\n')
        buff[my_strlen(buff) - 1] = '\0';
    if (is_nbr(buff) == 1 && isnb == 0) {
        maze->nbrobot = my_getnbr(buff);
        isnb = 1;
    }
    if (is_room(buff) == 1)
        nroom_set(&maze->room, buff);
    command_check(buff, nbline, buffsize, maze);
    if (is_tunnel(buff, maze) == 1) {
        ntunnel_set(&maze->tunnels, buff);
    }
    return 0;
}

int main(void)
{
    int nbline = 0;
    char *buff = NULL;
    maze_t maze = {0};
    size_t buffsize = 0;

    buffsize = getline(&buff, &buffsize, stdin);
    for (nbline = 1; (int)buffsize != -1; nbline ++) {
        if (struct_filler(&maze, buff, buffsize, &nbline) == -1)
            break;
        buffsize = getline(&buff, &buffsize, stdin);
    }
    if (maze.end == NULL || maze.start == NULL)
        return 84;
    printer(maze);
    algoritm(&maze);
}
