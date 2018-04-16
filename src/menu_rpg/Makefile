##
## EPITECH PROJECT, 2017
## Makefile
## File description:
###

SRC	=	src/init_menu/create_men.c	\
		src/init_menu/create_men2.c	\
		src/init_menu/create_set.c	\
		src/main.c			\


OBJ	=	$(SRC:.c=.o)

NAME	=	menu

CFLAGS	=	-W -Wall -Wextra  -I./include -g3

all: $(NAME) clean

$(NAME) :	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *#

re: clean all
