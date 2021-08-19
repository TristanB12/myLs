##
## EPITECH PROJECT, 2019
## C Pool EvalExpr
## File description:
## Project root Makefile
##

CC = gcc

SRC =	src/main.c		\
		src/mode.c		\
		src/octal.c		\
		src/initialisation.c	\
		src/functions.c 		\
		src/ll.c		\
		src/lt.c 		\
		src/lr.c 		\
		src/lrr.c  		\
		src/ls.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include/ -W -Wall -Wextra  $(DBFLAGS)

LDFLAGS = -L./lib/my -lmy

DBFLAGS = -g -g3 -ggdb

NAME = my_ls

all: $(NAME)

$(NAME):    libmy $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses $(CFLAGS) $(LDFLAGS)

libmy:
	make -C ./lib/my all

clean:
	rm -f $(OBJ)
	make -C ./lib/my/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean

re: fclean all
