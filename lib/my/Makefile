##
## EPITECH PROJECT, 2019
## Make file
## File description:
## make file
##

SRC	=	my_putstr.c			\
		my_strlen.c			\
		my_putchar.c		\
		my_put_nbr.c		\
		my_revstr.c			\
		my_strcmp.c 		\
		my_getnbr.c 		\
		my_strcat.c 		\
		convert_binary.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a


all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC)
	    ar rc -o $(NAME) *.o $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
