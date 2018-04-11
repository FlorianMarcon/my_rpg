/*
** EPITECH PROJECT, 2017
** create_line
** File description:
** create_line
*/

#include <SFML/Graphics.h>
#include "my.h"

sfVertexArray	*create_line(sfVector2f point1, sfVector2f point2, sfColor color)
{
	my_printf("HERE\n");
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = color};
	sfVertex vertex2 = {.position = point2, .color = color};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}
