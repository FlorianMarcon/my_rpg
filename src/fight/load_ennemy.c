/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** load_ennemy
*/

#include "game.h"

void	load_enn_value(ennemy_t *enn, char *buffer, int fd)
{
	buffer = get_next_line(fd);
	enn->vie_m = my_getnbr(buffer);
	buffer = get_next_line(fd);
	enn->vie = my_getnbr(buffer);
	buffer = get_next_line(fd);
	enn->att_m = my_getnbr(buffer);
	buffer = get_next_line(fd);
	enn->att_p = my_getnbr(buffer);
	buffer = get_next_line(fd);
	enn->defence = my_getnbr(buffer);
	buffer = get_next_line(fd);
	enn->xp_g = my_getnbr(buffer);
}

void	load_enn_sprite(ennemy_t *enn, int fd)
{
	char *buffer;

	buffer = get_next_line(fd);
	buffer = get_next_line(fd);
	printf("%s\n", buffer);
	enn->texture = sfTexture_createFromFile(buffer, NULL);
	enn->sprite = sfSprite_create();
	enn->rect.top = get_file_pos(fd, buffer);
	enn->rect.left = get_file_pos(fd, buffer);
	enn->rect.width = get_file_pos(fd, buffer);
	enn->rect.height = get_file_pos(fd, buffer);
	enn->position.x = get_file_pos(fd, buffer);
	enn->position.y = get_file_pos(fd, buffer);
	sfSprite_setTexture(enn->sprite, enn->texture, sfTrue);
	sfSprite_setPosition(enn->sprite, enn->position);
	sfSprite_setTextureRect(enn->sprite, enn->rect);

}

void	load_ennemy(game_t *game)
{
	char buffer[] = "./ennemies/200";
	int fd = 0;

//	buffer = my_strcat(buffer,
//	get_nb_in_char(game->map->map[game->perso->x][game->perso->y]));
//	buffer = "./ennemies/200";
	if ((fd = open(buffer, O_RDONLY)) == -1)
		return;
	load_enn_sprite(game->fight->ennemy, fd);
	load_enn_value(game->fight->ennemy, buffer, fd);
	//load_enn_rect();

	//free (buffer);
	close (fd);
}
