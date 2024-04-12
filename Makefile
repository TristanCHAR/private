##
## EPITECH PROJECT, 2024
## setting_up
## File description:
## Makefile
##

SRC = src/main.c \
      src/printers.c    \
      src/array_handler.c \
      src/room_handler.c      \
      src/tunnel_handler.c    \
      lib/my_getnbr.c \
      lib/my_strcat.c \
      lib/my_putstr.c \
      lib/my_putnbr.c \
      lib/my_putchar.c \
      lib/my_strcmp.c \
      lib/my_strlen.c \
      lib/strtoarr.c \
      lib/strtoarrfuncs.c

OBJ = $(SRC:.c=.o)

NAME = amazed

CFLAGS =

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

coding-style: fclean
	@coding-style . . && clear && cat coding-style-reports.log

debug: CFLAGS += -g3 -Wall -Wextra -Werror
debug: re

gdb: CFLAGS += -g
gdb: re
