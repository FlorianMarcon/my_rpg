/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** init_fight
*/

#include "game.h"

void	init_first_txt_fight_node(linked_txt_t *txt, int fd, char *data, sfFont *font)
{
	sfVector2f pos;
	sfColor textcolor = {255, 255, 255, 175};
	char *buffer = "\0";

	txt->text = sfText_create();
	pos.x = get_file_pos(fd, buffer);
	pos.x = 40;//800
	pos.y = get_file_pos(fd, buffer);
	sfText_setString(txt->text, data);
	sfText_setPosition(txt->text, pos);
	sfText_setFont(txt->text, font);
	sfText_setCharacterSize(txt->text, 40);
	sfText_setColor(txt->text, textcolor);
	txt->next = NULL;
}

void	create_txt_fight_node(linked_txt_t *txt, int fd, char *data, sfFont *font)
{
	sfVector2f pos;
	linked_txt_t *new = malloc(sizeof(stat_txt_t) * 1);
	char *buffer = "\0";
	sfColor textcolor = {255, 255, 255, 175};

	while (txt->next != NULL)
		txt = txt->next;
	new->text = sfText_create();
	pos.x = get_file_pos(fd, buffer);
	pos.y = get_file_pos(fd, buffer);
	sfText_setString(new->text, data);
	sfText_setPosition(new->text, pos);
	sfText_setFont(new->text, font);
	sfText_setCharacterSize(new->text, 40);
	sfText_setColor(new->text, textcolor);
	new->next = NULL;
	txt->next = new;

}
linked_txt_t *init_fight_txt(void)
{
	int fd = open("./src/fight/txt/file_txt", O_RDONLY);
	linked_txt_t *txt = malloc(sizeof(linked_txt_t) * 1);
	sfFont *font = sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf");
//	sfVector2f pos = {40, 750};

	if (fd == -1)
		return (NULL);
	init_first_txt_fight_node(txt, fd, "Lance baton (A)", font);
	create_txt_fight_node(txt, fd, "Wingardium (Q)", font);
	create_txt_fight_node(txt, fd, "Life : ", font);
	create_txt_fight_node(txt, fd, "Enn life :", font);
	return (txt);
}

item_t	*load_fight_item(void)
{
	int fd = open("./src/fight/item/fight_item", O_RDONLY);
	item_t *item = malloc(sizeof(item_t) * 1);
	char *buffer = "\0";
	sfVector2f pos = {0, 0};

	if (fd == -1)
		return (NULL);
	buffer = get_next_line(fd);
	init_first_item(item, buffer); //background
	sfSprite_setPosition(item->sprite, pos);
	create_item_node(item, fd, buffer); //stat_bar
	create_item_node(item, fd, buffer); //player sprite
	//			enn_sprite
	return (item);
}

ennemy_t	*init_ennemy(void)
{
	ennemy_t *enn = malloc(sizeof(ennemy_t) * 1);

	if (enn == NULL)
		return (NULL);
	enn->vie = 0;
	enn->vie_m = 0;
	enn->att_m = 0;
	enn->att_p = 0;
	enn->defence = 0;
	enn->xp_g = 0;
	return (enn);
}

fight_t	*init_fight(void)
{
	fight_t *fight = malloc(sizeof(fight_t) * 1);

	fight->fight_mode = 0;
	fight->txt = init_fight_txt();
	fight->item = load_fight_item();
	fight->ennemy = init_ennemy();
	return (fight);
}
