##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c			\
		$(WAY)/loop_game/loop_game.c	\
		$(WAY)/graphique/generate_window.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 -I./include

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lm

WAY_LIB	=	./lib/my

WAY_TST	=	./tests

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	my_rpg

all:	$(OBJ)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
	make clean -C./$(WAY_TST)
	make clean -C./$(WAY_LIB)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C./$(WAY_TST)
	make fclean -C./$(WAY_LIB)
	$(RM) $(NAME)

re:	clean all

tests_run:
	make -C./$(WAY_TST)
