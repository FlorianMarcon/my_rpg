/*
** EPITECH PROJECT, 2017
** generate_sprite_from_file
** File description:
** generate_sprite_from_file
*/

#include <SFML/Graphics.h>

sfSprite	*generate_sprite_from_file(char *path)
{
	sfSprite *sprite = sfSprite_create();
	sfTexture *text;

	if (sprite == NULL)
		return (NULL);
	text = sfTexture_createFromFile(path, NULL);
	if (text == NULL) {
		sfSprite_destroy(sprite);
		return (NULL);
	}
	sfSprite_setTexture(sprite, text, sfTrue);
	//sfTexture_destroy(text);
	return (sprite);
}
