/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** init_item
*/

#include "game.h"

void	create_item_node(item_t *item, int fd, char *buffer)
{
	item_t *new = malloc(sizeof(item_t) * 1);

	while (item->next != NULL)
		item = item->next;
	if ((buffer = get_next_line(fd)) == NULL || buffer[0] == '\0')
		return;
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(buffer, NULL);
	new->position.x = get_file_pos(fd, buffer);
	new->position.y = get_file_pos(fd, buffer);
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setPosition(new->sprite, new->position);
	new->next = NULL;
	item->next = new;
}

void	init_first_item(item_t *item, char *buffer)
{
	item->sprite = sfSprite_create();
	item->texture = sfTexture_createFromFile(buffer, NULL);
	item->position.x = 0;
	item->position.y = 800;
	item->next = NULL;
	sfSprite_setTexture(item->sprite, item->texture, sfTrue);
	sfSprite_setPosition(item->sprite, item->position);
}

item_t	*init_stat_item(void)
{
	item_t *item = malloc(sizeof(item_t) * 1);
	int fd = open("./src/stat/path_obj_stat", O_RDONLY);
	char *buffer = "\0";
	int i = 0;

	if (fd == -1)
		return (NULL);
	if ((buffer = get_next_line(fd)) == NULL || buffer[0] == '\0')
		return (NULL);
	init_first_item(item, buffer);
	while (++i != 7) {
		create_item_node(item, fd, buffer);
	}
	close (fd);
	return (item);
}
