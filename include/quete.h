/*
** EPITECH PROJECT, 2017
** quete
** File description:
** quete
*/

#ifndef QUETE_
#define QUETE_

#include <stdbool.h>
#include "my.h"

typedef struct quete_s {
	int id;
	char *message[9];
	unsigned int size_message;
	linked_list_t *obj_need;
	bool validated;
} quete_t;

quete_t	*create_quete(char *path);

linked_list_t	*generate_list_quete(char *path);
#endif
