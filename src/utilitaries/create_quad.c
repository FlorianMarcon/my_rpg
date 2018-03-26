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
