##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC	=	anime_moi.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CC	=	gcc 

FLAGS   =       -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
