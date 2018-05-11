/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** main_fight
*/

#include "game.h"

void	wait_sec(float sec)
{
	sfClock *my_clock;
	sfTime my_time;
	float second;;

	my_clock = sfClock_create();
	while (second < sec) {
		my_time = sfClock_getElapsedTime(my_clock);
		second = my_time.microseconds / 1000000.0;
	}
}

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

void	load_enn_sprite(ennemy_t *enn, int fd, char *buffer)
{

	buffer = get_next_line(fd);
	printf("%s\n", buffer);
	enn->texture = sfTexture_createFromFile(buffer, NULL);
	enn->sprite = sfSprite_create();
	/*perso->rect.top = 0;
	perso->rect.left = 0;
	perso->rect.width = 32;
	perso->rect.height = 48;*/
	enn->position.x = get_file_pos(fd, buffer);
	enn->position.y = get_file_pos(fd, buffer);
	sfSprite_setTexture(enn->sprite, enn->texture, sfTrue);
	sfSprite_setPosition(enn->sprite, enn->position);
	//sfSprite_setTextureRect(perso->sprite, perso->rect);

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
	load_enn_sprite(game->fight->ennemy, fd, buffer);
	load_enn_value(game->fight->ennemy, buffer, fd);
	//free (buffer);
}

void	load_stat(game_t *game, linked_txt_t *txt)
{
	char *buffer;

	sfText_setString(txt->text, "Attack :");
	txt = txt->next;
	sfText_setString(txt->text, "Lance baton (A)");
	txt = txt->next;
	sfText_setString(txt->text, "Wingardium (Q)");
	txt = txt->next;
	buffer = my_strcat("Vie : ", get_nb_in_char(game->perso->stat.vie_c));
	buffer = my_strcat(buffer, " / ");
	buffer = my_strcat(buffer, get_nb_in_char(game->perso->stat.vie));
	sfText_setString(txt->text, buffer);
	txt = txt->next;
	buffer = my_strcat("Vie enn : ",\
		get_nb_in_char(game->fight->ennemy->vie));
	buffer = my_strcat(buffer, " / ");
	buffer = my_strcat(buffer, get_nb_in_char(game->fight->ennemy->vie_m));
	sfText_setString(txt->text, buffer);
	free (buffer);
}

/*int	loop_fight(game_t *game)
{
	return (1);
}*/

void	event_fight(game_t *game)
{
	int i = 0;

	while (i == 0) {
		while (sfRenderWindow_pollEvent(game->win->window,\
		&game->win->event)) {
			if (game->win->event.type == sfEvtClosed) {
				sfRenderWindow_close(game->win->window);
				return;
			}
		}
		if (sfKeyboard_isKeyPressed(sfKeyA)) {
			lance_baton(game);
			i = 1;
		}
		if (sfKeyboard_isKeyPressed(sfKeyQ)) {
			wingardium(game);
			i = 1;
		}
	}
	wait_sec(2);
}

/*void	ennemy_tour(void)
{
	int i = rand()
	if (i == 1)
		att_p
	else
		att_m

}



void	modify_fight_stat(game_t *game)
{

}*/

int	check_life(game_t *game)
{
	sfText *txt = sfText_create();
	sfVector2f pos = {200, 300};
	sfFont *fo = sfFont_createFromFile("font/attack_of_the_cucumbers.ttf");

	sfText_setFont(txt, fo);
	sfText_setCharacterSize(txt, 90);
	sfText_setColor(txt, sfGreen);
	sfText_setPosition(txt, pos);
	if (game->perso->stat.vie_c == 0) {
		sfText_setString(txt, "YOU LOST");
		display_fight(game, txt);
		wait_sec(3);
		return (0);
	}
	if (game->fight->ennemy->vie == 0) {
		sfText_setString(txt, "YOU WIN");
		display_fight(game, txt);
		wait_sec(3);
		return (0);
	}
	return (1);
}

void	run_fight(game_t *game)
{
	int i = 1;

	load_ennemy(game);
	while (i == 1) {
		load_stat(game, game->fight->txt);
		display_fight(game, NULL);
		while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
			if (game->win->event.type == sfEvtClosed) {
				sfRenderWindow_close(game->win->window);
				return;
			}
		}
		event_fight(game);
		load_stat(game, game->fight->txt);
		i = check_life(game);
		if (i == 0)
			return;
		display_fight(game, NULL);
		ennemy_tour(game);
		i = check_life(game);
	}
}