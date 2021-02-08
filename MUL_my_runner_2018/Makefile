##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC	=	main.c	\
		paralax.c	\
		player.c	\
		life_mob.c	\
		gravity.c	\
		score_musique.c	\
		victory_colision.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CC	=	gcc -g3

FLAGS   =       -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -g3

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -I include -o $(NAME) $(SRC) $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
