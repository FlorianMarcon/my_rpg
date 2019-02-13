/*
** EPITECH PROJECT, 2017
** generate_list_quete
** File description:
** generate_list_quete
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "quete.h"
#include "game.h"

linked_list_t	*generate_list_quete_create(char *way, linked_list_t *list)
{
	quete_t *quete = create_quete(way);

	if (quete != NULL) {
		if (list == NULL) {
			list = create_list(quete);
		} else
			create_node(list, quete);
	}
	return (list);
}
linked_list_t	*generate_list_quete(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "quete")) {
			list = generate_list_quete_create(way, list);
		}
		free(way);
	}
	closedir(dir);
	return (list);
}
