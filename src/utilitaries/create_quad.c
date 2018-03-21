/*
** EPITECH PROJECT, 2017
** create_quad
** File description:
** create_quad
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "map.h"

sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = point2, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = point3, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = point4, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 0}};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2)
{
	sfVector2f point3 = {point2.x, point2.y + 50};
	sfVector2f point4 = {point1.x, point1.y + 50};

	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 0}};
	sfVertex vertex2 = {.position = point2, .color = sfWhite,\
					.texCoords = (sfVector2f){0, 100}};
	sfVertex vertex3 = {.position = point3, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 100}};
	sfVertex vertex4 = {.position = point4, .color = sfWhite,\
					.texCoords = (sfVector2f){100, 0}};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

sfVector2f	project_iso_point(int x, int y, map_t *map)
{
	sfVector2f point;
	double rota = ROTATION * M_PI / 180;
	double incli = INCLINAISON * M_PI / 180;

	point.x = (map->x_center + cos(rota) * (x - map->x_center));
	point.x -= sin(rota) * (y - map->y_center);
	point.y = (map->y_center + sin(rota) * (x - map->x_center));
	point.y += cos(rota) * (y - map->y_center);
	point.y = map->y_center  + cos(incli) * (point.y - map->y_center);
	point.x += TRANSLA_X;
	point.y += TRANSLA_Y;
	point.x = point.x * (SCALING_X);
	point.y = point.y * (SCALING_Y);
	return (point);
}

sfVector2f	**create_two_d_map(map_t *map)
{
	int i = 0;
	int j = 0;
	sfVector2f **map_iso;

	map_iso = malloc(sizeof(sfVector2f*) * map->height);
	while (j < map->height) {
		i = 0;
		map_iso[j] = malloc(sizeof(sfVector2f) * map->width);
		while (i < map->width) {
			map_iso[j][i] = project_iso_point(i, j, map);
			i++;
		}
		j++;
	}
	return (map_iso);
}
