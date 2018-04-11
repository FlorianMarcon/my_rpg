##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

CC	=	gcc

WAY	=	../src

SRC	=	$(WAY)/map/fill_map.c			\
		$(WAY)/map/fill_matter.c		\
		$(WAY)/map/fill_setting.c		\
		$(WAY)/map/generate_map.c		\
		$(WAY)/map/generate_sprite_map.c	\
		$(WAY)/map/generate_list_map.c		\
		$(WAY)/map/generate_object.c		\
		$(WAY)/map/search_map.c			\
		$(WAY)/utilitaries/create_quad.c		\
		$(WAY)/utilitaries/project_iso_point.c		\
		$(WAY)/utilitaries/create_two_d_map.c		\
		$(WAY)/graphique/generate_sprite_from_file.c	\

SRC_UT	=	./map/fill/tests_utils.c		\
		./map/fill/tests_utils_second.c		\
		./map/generate_list_map/tests_utils.c	\
		./map/search_map/tests_utils.c		\
		./map/generate_object/tests_utils.c	\
		./graphique/generate_sprite_from_file/tests_utils.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -g3 --coverage -I../include

LDFLAGS	=	-lcriterion -lgcov -lcsfml-system -lcsfml-window -lcsfml-graphics -lm

WAY_LIB	=	../lib/my

LIB	=	-L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	make -C./$(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_UT) $(LIB) $(LDFLAGS)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
