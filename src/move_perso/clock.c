/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** clock
*/

#include "game.h"

my_clock_t	*init_clock(void)
{
	my_clock_t	*my_clock = malloc(sizeof(my_clock_t) * 1);

	if (my_clock == NULL)
		return (NULL);
	my_clock->my_clock = sfClock_create();
	my_clock->my_time = sfClock_getElapsedTime(my_clock->my_clock);
	my_clock->second = my_clock->my_time.microseconds / 1000000.0;
	my_clock->next = NULL;
	return (my_clock);
}

my_clock_t	*update_time(my_clock_t *my_clock)
{
	my_clock->my_time = sfClock_getElapsedTime(my_clock->my_clock);
	my_clock->second = my_clock->my_time.microseconds / 1000000.0;
	return (my_clock);
}
