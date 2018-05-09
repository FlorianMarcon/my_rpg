/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** init_stat
*/

#include "stat.h"

int	get_file_pos(int fd, char *buffer)
{
	if ((buffer = get_next_line(fd)) == NULL || buffer[0] == '\0')
		return (-500);
	return (my_getnbr(buffer));
}

chstat_t	*init_stat(stat_t stat)
{
	chstat_t *st = malloc(sizeof(chstat_t) * 1);

	st->item = init_stat_item();
	st->txt = init_stat_txt(stat);
	return (st);
}
