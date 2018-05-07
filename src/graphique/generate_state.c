/*
** EPITECH PROJECT, 2017
** generate_state
** File description:
** generate_state
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

sfRenderStates 	*generate_state(char *str, char *shader)
{
	sfRenderStates *states;

	if (str == NULL)
		return (NULL);
	if ((states = malloc(sizeof(*states))) == NULL) {
		free(str);
		return (NULL);
	}
	states->blendMode = sfBlendNone;
	states->transform = sfTransform_Identity;
	if (shader == NULL)
		states->shader = NULL;
	else
		states->shader = sfShader_createFromFile("./shader/simple.vert", shader);
//	states->shader = sfShader_createFromFile("./shader/simple.vert", NULL, shader);
	states->texture = sfTexture_createFromFile(str, NULL);
	if (states->texture == NULL) {
		free(states);
		states = NULL;
	}
	return (states);
}
