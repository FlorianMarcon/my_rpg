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
#include "inventory.h"

typedef struct toto {
	char *name;
	int quantity;
}toto_t;

typedef struct quete_s {
	int id;

	char *message_no_val[9];
	unsigned int size_message_no_val;
	char *message_val[9];
	unsigned int size_message_val;

	linked_list_t *obj_need;

	linked_list_t *obj_given;

	bool validated;
} quete_t;

quete_t	*create_quete(char *path);

linked_list_t	*generate_list_quete(char *path);

#endif
