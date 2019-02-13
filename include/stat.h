/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** stat header
*/

#ifndef STAT_
#define STAT_

#include "graphique.h"
#include "move_perso.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

typedef	struct item_s
{
	char const	*name;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	position;
	struct item_s	*next;
} item_t;

typedef	struct	stat_txt_t
{
	sfText*	txt;
	struct stat_txt_t *next;
} stat_txt_t;

typedef	struct	chstat_s
{
	item_t *item;
	stat_txt_t *txt;
} chstat_t;

stat_txt_t	*init_stat_txt(stat_t stat);

item_t	*init_stat_item(void);

int	get_file_pos(int fd, char *buffer);

chstat_t	*init_stat(stat_t stat);

char	*get_nb_in_char(int nb);

void	init_first_item(item_t *item, char *buffer);

void	create_item_node(item_t *item, int fd, char *buffer);

#endif
