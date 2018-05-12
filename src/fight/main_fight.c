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

void	load_stat(game_t *game, linked_txt_t *txt)
{
	char *buffer;

	sfText_setString(txt->text, "Lance baton (A)");
	txt = txt->next;
	sfText_setString(txt->text, "Wingardium (Q)");
	txt = txt->next;
	buffer = my_strcat("Vie : ", get_nb_in_char(game->perso->stat.vie_c));
	buffer = my_strcat(buffer, " / ");
	buffer = my_strcat(buffer, get_nb_in_char(game->perso->stat.vie));
	sfText_setString(txt->text, buffer);
	txt = txt->next;
	buffer = my_strcat("Vie enn : ", get_nb_in_char(game->fight->ennemy->vie));
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
		while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
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
}

/*void	ennemy_tour()
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
	sfVector2f pos = {300, 300};
	sfFont *font = sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf");

	sfText_setFont(txt, font);
	sfText_setCharacterSize(txt, 90);
	sfText_setColor(txt, sfGreen);
	sfText_setPosition(txt, pos);
	if (game->perso->stat.vie_c == 0) {
		sfText_setString(txt, "YOU LOST");
		display_fight(game, txt);
		game->perso->stat.xp += game->fight->ennemy->xp_g / 2;
		game->perso->stat.vie_c = game->perso->stat.vie;
		wait_sec(3);
		return (0);
	}
	if (game->fight->ennemy->vie == 0) {
		sfText_setString(txt, "YOU WIN");
		display_fight(game, txt);
		game->perso->stat.xp += game->fight->ennemy->xp_g;
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
