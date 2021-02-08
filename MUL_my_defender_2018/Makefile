##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC     =	main.c	\
		game.c	\
		help.c	\
		entity.c	\
		speed_menu.c	\
		set_tower.c	\
		button_menu.c	\
		escape.c	\
		end.c	\
		life_mob.c

NAME    =       my_defender

CC      =       gcc

RM      =       rm -f

CFLAGS	=	-I ./include -g3

FLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -g3

OBJ	=	$(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -I ./include -o $(NAME) $(OBJ) $(FLAGS) -g3

clean:
		$(RM) $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:	clean fclean re all
