/*
** EPITECH PROJECT, 2017
** create_quete
** File description:
** create_quete
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "quete.h"
#include "my.h"

toto_t	*create_toto(char *str)
{
	toto_t *toto = malloc(sizeof(*toto));
	char **tab = parsing_str(str, ' ' | '\t');

	if (toto == NULL || tab == NULL)
		return (NULL);
	toto->name = tab[0];
	toto->quantity = my_getnbr(tab[1]);
	free(str);
	return (toto);
}
void	quete_stock_object_to_come_back(quete_t *quete, int fd)
{
	char *str = NULL;

	while ((str = get_next_line(fd)) != NULL &&
					my_strcmp(str, "TO BE GIVEN") != 0) {
		if (quete->obj_need == NULL)
			quete->obj_need = create_list(create_toto(str));
		else
			create_node(quete->obj_need, create_toto(str));
	}
	if (str != NULL)
		free(str);
	while ((str = get_next_line(fd)) != NULL) {
		if (quete->obj_given == NULL)
			quete->obj_given = create_list(create_toto(str));
		else
			create_node(quete->obj_given, create_toto(str));
	}
}
void	quete_stock_message(quete_t *quete, int fd)
{
	unsigned int i = 0;
	char *str = get_next_line(fd);

	while ((str = get_next_line(fd)) != NULL &&
					my_strcmp(str, "MSG VAL") != 0) {
		quete->message_no_val[i++] = str;
	}
	quete->size_message_no_val = i;
	if (str != NULL)
		free(str);
	i = 0;
	while ((str = get_next_line(fd)) != NULL &&
					my_strcmp(str, "MUST BE GIVEN") != 0) {
		quete->message_val[i++] = str;
	}
	quete->size_message_val = i;
	if (str != NULL)
		free(str);
}

quete_t	*create_quete(char *path)
{
	quete_t *quete = malloc(sizeof(*quete));
	char *str;
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1 || quete == NULL)
		return (NULL);
	str = get_next_line(fd);
	quete->obj_need = NULL;
	quete->obj_given = NULL;
	quete->id = my_getnbr(str);
	quete->validated = false;
	free(str);
	quete_stock_message(quete, fd);
	quete_stock_object_to_come_back(quete, fd);
	return (quete);
}
