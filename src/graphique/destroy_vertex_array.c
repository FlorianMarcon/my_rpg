/*
** EPITECH PROJECT, 2017
** destroy_vertex_array
** File description:
** destroy_vertex_array
*/

#include "graphique.h"
#include <stdlib.h>

void	destroy_vertex_array(sfVertexArray **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}
