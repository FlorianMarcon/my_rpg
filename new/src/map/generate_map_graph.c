/*
** EPITECH PROJECT, 2017
** generate_map_graph
** File description:
** generate_map_graph
*/

#include "map.h"
#include "game.h"
#include "graphique.h"

sfVertexArray	**generate_sprite_floor(map_graph_t *map)
{
	sfVector2f **iso = map->iso;
	sfVertexArray **floor;
	int a = 0;

	floor = malloc(sizeof(*floor) * ((map->map->width - 1) * (map->map->height - 1) + 1));
	if (floor == NULL) {
		return (NULL);
	}
	for (int j = 0; j < map->map->height - 1; j++) {
		for (int i = 0; i < map->map->width - 1; i++) {
			floor[a++] = create_quad(iso[j][i], iso[j][i + 1], iso[j + 1][i + 1], iso[j + 1][i]);
		}
	}
	floor[a] = NULL;
	return (floor);
}

sfVertexArray	**generate_sprite_bottom(map_graph_t *map)
{
	sfVector2f **iso = map->iso;
	sfVertexArray **bot;
	int o = 0;

	bot = malloc(sizeof(*bot) * (map->map->width * map->map->height));
	if (bot == NULL)
		return (NULL);
	for (int j = 0; j < map->map->height - 1; j++) {
		for (int i = 0; i < map->map->width - 1; i++) {
			if (i == map->map->width - 2)
			bot[o++] = create_quad_bottom_map(iso[j][i + 1], iso[j + 1][i + 1]);
			if (j == map->map->height - 2)
			bot[o++] = create_quad_bottom_map(iso[j + 1][i], iso[j + 1][i + 1]);

		}
	}
	bot[o] = NULL;
	return (bot);
}

sfVertexArray	**generate_sprite_line(map_graph_t *map)
{
	sfVector2f **iso = map->iso;
	sfVertexArray **arr_line;
	int a = 0;

	if ((arr_line = malloc(sizeof(*arr_line) * ((map->map->width) * (map->map->height) * 3))) == NULL)
		return (NULL);
	for (int j = 0; j < map->map->height - 1; j++) {
		for (int i = 0; i < map->map->width - 1; i++) {
			arr_line[a++] = create_line(iso[j][i], iso[j][i + 1], sfBlack);
			arr_line[a++] = create_line(iso[j][i], iso[j + 1][i], sfBlack);
		}
	}
	arr_line[a] = NULL;
	return (arr_line);
}

map_graph_t	*generate_map_graph(map_t *map, game_t *game)
{
	map_graph_t *graph;

	(void)game;
	if (map == NULL)
		return (NULL);
	if ((graph = malloc(sizeof(*graph))) == NULL)
		return (NULL);
	graph->map = map;
	graph->iso = create_two_d_map(map);
	map->iso = create_two_d_map(map);
	graph->arr_floor = generate_sprite_floor(graph);
	graph->state_floor = generate_state(map->path_sprite_floor, NULL);
	graph->arr_bottom = generate_sprite_bottom(graph);
	graph->state_bottom = generate_state(map->path_sprite_bottom, NULL);
	graph->arr_line = generate_sprite_line(graph);
	graph->list_obj = generate_list_sprite(map, game->list_obj);
	return (graph);
}
