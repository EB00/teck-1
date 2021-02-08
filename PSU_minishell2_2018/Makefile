##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

SRC     =	main.c	\
		my_array.c	\
		my_array2.c	\
		str_compare.c	\
		fonction.c	\
		fonction2.c	\
		fonction_other.c	\
		my_getnbr.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

CC      =       gcc

RM      =       rm -f


all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -I include -o $(NAME) $(SRC)

clean:
		rm -f vgcore*
		rm -f *#
		rm -f *~
		$(RM) $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

