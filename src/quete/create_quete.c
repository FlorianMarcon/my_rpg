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

quete_t	*create_quete(char *path)
{
	quete_t *quete = malloc(sizeof(*quete));
	char *str;
	int fd;
	unsigned int i = 0;

	if ((fd = open(path, O_RDONLY)) == -1 || quete == NULL)
		return (NULL);
	str = get_next_line(fd);
	quete->obj_need = NULL;
	quete->id = atoi(str);
	quete->validated = false;
	free(str);
	while ((str = get_next_line(fd)) != NULL && strcmp(str, "MESSAGE") != 0) {
		if (quete->obj_need == NULL)
			quete->obj_need = create_list(str);
		else
			create_node(quete->obj_need, str);
	}
	free(str);
	for (; i != 8 && (quete->message[i] = get_next_line(fd)) != NULL; i++);
	quete->size_message = i;
	return (quete);
}
