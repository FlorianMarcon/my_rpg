/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "game.h"
#include "map.h"
map_t	*generate_map(char *path);

int	main(int ac, char **av)
{
	if (ac == 2) {
		loop_game(av[1]);
		return (0);
	}
	return (84);
}
