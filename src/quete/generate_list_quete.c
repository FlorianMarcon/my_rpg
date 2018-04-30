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

linked_list_t	*generate_list_quete(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	quete_t *quete;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "quete"))
			quete = create_quete(way);
		else
			quete = NULL;
		if (quete != NULL) {
			if (list == NULL) {
				list = create_list(quete);
			} else
				create_node(list, quete);
		}
		free(way);
	}
	closedir(dir);
	return (list);
}
