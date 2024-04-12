/*
** EPITECH PROJECT, 2024
** B-CPE-200-PAR-2-1-amazed-ziad.bengherabi
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

typedef struct room_s {
    char *name;
    int x;
    int y;
} room_t;

typedef struct tunnels_s {
    char **arrtunnel;
    int is_visited;
} tunnels_t;

typedef struct maze_s {
    int nbrobot;
    room_t *room;
    char **start;
    char **end;
    tunnels_t *tunnels;
} maze_t;

typedef struct queue_node {
    char *data;
    struct queue_node *next;
} path_t;

typedef struct {
    path_t *front;
    path_t *back;
} side_t;

int my_getnbr(char const *str);
char *my_strcat(char *dest, const char *src);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strcmp(const char *s1, const char *s2);
char **strtoarr(char *str, char *sep);
int my_arrlen(char **arr);
char **my_arrdup(char **arr);
void free_array(char ***array);
int my_strlen(char const *str);
#endif /* !MY_H_ */
