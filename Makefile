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
		$(WAY)/graphique/generate_sprite_from_file.c	\
		$(WAY)/graphique/display_sprite.c	\
		$(WAY)/map/fill_map.c		\
		$(WAY)/map/fill_matter.c		\
		$(WAY)/map/fill_setting.c		\
		$(WAY)/map/generate_map.c		\
		$(WAY)/map/generate_list_map.c		\
		$(WAY)/map/generate_sprite_map.c	\
		$(WAY)/map/display_map.c		\
		$(WAY)/map/search_map.c			\
		$(WAY)/utilitaries/create_quad.c		\
		$(WAY)/utilitaries/project_iso_point.c		\
		$(WAY)/utilitaries/create_two_d_map.c		\
		$(WAY)/utilitaries/create_line.c		\
		$(WAY)/utilitaries/initialisation_game.c	\
		$(WAY)/utilitaries/display.c			\

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
