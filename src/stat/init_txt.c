/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** init_txt
*/

#include "game.h"

void	init_first_txt_node(stat_txt_t *txt, int fd, char *data, sfFont *font)
{
	sfVector2f pos;
	sfColor textcolor = {255, 255, 255, 175};
	char *buffer = "\0";

	txt->txt = sfText_create();
	pos.x = get_file_pos(fd, buffer);
	pos.x = 800;
	pos.y = get_file_pos(fd, buffer);
	sfText_setString(txt->txt, data);
	sfText_setPosition(txt->txt, pos);
	sfText_setFont(txt->txt, font);
	sfText_setCharacterSize(txt->txt, 50);
	sfText_setColor(txt->txt, textcolor);
	txt->next = NULL;
}

void	create_txt_node(stat_txt_t *txt, int fd, char *data, sfFont *font)
{
	sfVector2f pos;
	stat_txt_t *new = malloc(sizeof(stat_txt_t) * 1);
	char *buffer = "\0";
	sfColor textcolor = {255, 255, 255, 175};

	while (txt->next != NULL)
		txt = txt->next;
	new->txt = sfText_create();
	pos.x = get_file_pos(fd, buffer);
	pos.y = get_file_pos(fd, buffer);
	sfText_setString(new->txt, data);
	sfText_setPosition(new->txt, pos);
	sfText_setFont(new->txt, font);
	sfText_setCharacterSize(new->txt, 50);
	sfText_setColor(new->txt, textcolor);
	new->next = NULL;
	txt->next = new;
}

void	not_in_config_file(stat_txt_t *txt, int fd, sfFont *font)
{
	create_txt_node(txt, fd, ":\t /\0", font);
	create_txt_node(txt, fd, ":\t /\0", font);
	create_txt_node(txt, fd, ":\0", font);
	create_txt_node(txt, fd, ":\0", font);
	create_txt_node(txt, fd, ":\0", font);
	create_txt_node(txt, fd, "LVL :\0", font);
}

stat_txt_t	*init_stat_txt(stat_t stat)
{
	stat_txt_t *txt = malloc(sizeof(stat_txt_t) * 1);
	int fd = open("./src/stat/pos_txt", O_RDONLY);
	sfFont* font;

	font = sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf");
	if (fd == -1)
		return (NULL);
	init_first_txt_node(txt, fd, get_nb_in_char(stat.vie), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.att_m), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.att_p), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.defence), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.xp), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.xp_max), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.lvl), font);
	create_txt_node(txt, fd, get_nb_in_char(stat.vie_c), font);
	not_in_config_file(txt, fd, font);
	return (txt);
}
