##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	./src

SRC	=	$(WAY)/main.c			\
		$(WAY)/event.c			\

SRC	+=	$(WAY)/move_perso/win.c			\
		$(WAY)/move_perso/clock.c		\
		$(WAY)/move_perso/create_perso.c	\
		$(WAY)/move_perso/deplacement.c		\
		$(WAY)/move_perso/display.c		\
		$(WAY)/move_perso/move_perso.c	\
		$(WAY)/move_perso/detect_obj.c		\
		$(WAY)/move_perso/replace_perso.c	\
		$(WAY)/game/loop_game.c	\
		$(WAY)/game/initialisation_game.c	\
		$(WAY)/map/generate_map.c		\
		$(WAY)/map/generate_list_map.c		\
		$(WAY)/map/generate_map_graph.c		\
		$(WAY)/map/destroy.c		\
		$(WAY)/map/search_map.c		\
		$(WAY)/utilitaries/change_map.c		\
		$(WAY)/utilitaries/is_extension.c	\
		$(WAY)/utilitaries/create_two_d_map.c	\
		$(WAY)/utilitaries/create_quad.c	\
		$(WAY)/utilitaries/project_iso_point.c	\
		$(WAY)/utilitaries/display.c	\
		$(WAY)/utilitaries/display_map.c	\
		$(WAY)/graphique/generate_window.c	\
		$(WAY)/graphique/generate_sprite_from_file.c	\
		$(WAY)/graphique/display_sprite.c	\
		$(WAY)/graphique/generate_state.c	\
		$(WAY)/graphique/destroy_vertex_array.c	\
		$(WAY)/object/generate_object.c		\
		$(WAY)/object/generate_list_object.c		\
		$(WAY)/object/search_object.c		\
		$(WAY)/menu/anim_button.c			\
		$(WAY)/menu/anim_settings.c			\
		$(WAY)/menu/create_men.c			\
		$(WAY)/menu/create_men2.c			\
		$(WAY)/menu/create_set.c			\
		$(WAY)/menu/menu_crea.c			\
		$(WAY)/menu/loop_menu.c			\
		$(WAY)/inventory/launch_inventory.c			\
		$(WAY)/inventory/create_inventory.c			\
		$(WAY)/quete/create_quete.c		\
		$(WAY)/quete/generate_list_quete.c		\
		$(WAY)/quete/run_quete.c		\
		$(WAY)/quete/display_quete.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g3 -I./include

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
