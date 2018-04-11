/*
** EPITECH PROJECT, 2017
** destroy_map_graph
** File description:
** destroy_map_graph
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "map.h"

void	destroy_map_graph(map_graph_t *map)
{
	destroy_vertex_array(map->arr_floor);
	destroy_vertex_array(map->arr_bottom);
	destroy_vertex_array(map->arr_line);
	free(map->state_floor);
	free(map->state_bottom);
	free(map);
}
