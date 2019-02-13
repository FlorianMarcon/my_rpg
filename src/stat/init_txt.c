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
	pos.x = 130;
	pos.y = get_file_pos(fd, buffer);
	sfText_setString(txt->txt, data);
	sfText_setPosition(txt->txt, pos);
	sfText_setFont(txt->txt, font);
	sfText_setCharacterSize(txt->txt, 40);
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
	sfText_setCharacterSize(new->txt, 40);
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
	create_txt_node(txt, fd, " ", font);
}

stat_txt_t	*init_stat_txt(stat_t stat)
{
	stat_txt_t *txt = malloc(sizeof(stat_txt_t) * 1);
	int fd = open("./src/stat/pos_txt2", O_RDONLY);
	sfFont* font;
	char *buffer = "NTM";

	font = sfFont_createFromFile("./font/fibre-font.otf");
	if (fd == -1)
		return (NULL);
	init_first_txt_node(txt, fd, buffer, font);
	buffer = my_strcat(get_nb_in_char(stat.xp), " / ");
	buffer = my_strcat(buffer, get_nb_in_char(stat.xp_max));
	create_txt_node(txt, fd, buffer, font);
	buffer = my_strcat(": ", get_nb_in_char(stat.vie_c));
	buffer = my_strcat(buffer, " / ");
	buffer = my_strcat(buffer, get_nb_in_char(stat.vie));
	create_txt_node(txt, fd, buffer, font);
	buffer = my_strcat(": " , get_nb_in_char(stat.defence));
	create_txt_node(txt, fd, buffer, font);
	buffer = my_strcat(": ", get_nb_in_char(stat.att_m));
	create_txt_node(txt, fd, buffer, font);
	buffer = my_strcat(": ", get_nb_in_char(stat.att_p));
	create_txt_node(txt, fd, buffer, font);
	free (buffer);
	return (txt);
}
