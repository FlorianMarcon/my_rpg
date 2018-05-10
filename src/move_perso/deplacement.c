/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** deplacement
*/

#include "game.h"

my_clock_t	*init_linked_clock(void)
{
	my_clock_t *my_clock = init_clock();
	my_clock_t *clock2 = init_clock();

	if ((my_clock->next = malloc(sizeof(my_clock_t *))) == NULL)
		return (0);
	my_clock->next = clock2;
	return (my_clock);
}

void	loop_move(my_clock_t *my_clock, perso_t *perso, window_t *win)
{
	while (sfRenderWindow_pollEvent(win->window, &win->event)) {
		if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
	}
	update_time(my_clock);
	update_time(my_clock->next);
	if (my_clock->next->second > 0.04) {
		sfClock_restart(my_clock->next->my_clock);
		move_perso(perso, my_clock);
	}
}

void	dep_right(game_t *game)
{
	float x = game->perso->position.x;
	float y = game->perso->position.y;
	my_clock_t *my_clock = init_linked_clock();

	game->perso->mouvement.y = 0;
	game->perso->mouvement.x = 1;
	if (game->perso->x != 0 && detect_col(game, 1) != -1) {
		while (game->perso->position.x < x + 26.4 &&
					game->perso->position.y < y + 18.2) {
			loop_move(my_clock, game->perso, game->win);
			display(game, NULL, NULL);
		}
		game->perso->x -= 1;
		game->perso->position.x = game->map->iso[game->perso->x][game->perso->y].x - 10;
		game->perso->position.y = game->map->iso[game->perso->x][game->perso->y].y - 27;
		game->perso->mouvement.x = 0;
		sfSprite_setPosition(game->perso->sprite, game->perso->position);
	}
	free(my_clock);
}

void	dep_left(game_t *game)
{
	float x = game->perso->position.x;
	float y = game->perso->position.y;
	my_clock_t *my_clock = init_linked_clock();

	game->perso->mouvement.y = 0;
	game->perso->mouvement.x = -1;
	if (game->perso->x != game->map->height - 2 && detect_col(game, 0) != -1) {
		while (game->perso->position.x < x + 26 && game->perso->position.y < y + 18) {
			loop_move(my_clock, game->perso,game-> win);
			display(game, NULL, NULL);
		}
		game->perso->x += 1;
		game->perso->position.x = game->map->iso[game->perso->x][game->perso->y].x - 10;
		game->perso->position.y = game->map->iso[game->perso->x][game->perso->y].y - 27;
		game->perso->mouvement.x = 0;
		sfSprite_setPosition(game->perso->sprite, game->perso->position);
	}
	free(my_clock);
}

void	dep_down(game_t *game)
{
	float x = game->perso->position.x;
	float y = game->perso->position.y;
	my_clock_t *my_clock = init_linked_clock();

	if (game->perso->y != game->map->width - 2 && detect_col(game, 10) != -1) {
		game->perso->mouvement.x = 0;
		game->perso->mouvement.y = -1;
		while (game->perso->position.x < x + 36.4 && game->perso->position.y < y + 13.4) {
			loop_move(my_clock, game->perso, game->win);
			display(game, NULL, NULL);
		}
		game->perso->y += 1;
		game->perso->position.x = game->map->iso[game->perso->x][game->perso->y].x - 10;
		game->perso->position.y = game->map->iso[game->perso->x][game->perso->y].y - 27;
		game->perso->mouvement.y = 0;
		sfSprite_setPosition(game->perso->sprite, game->perso->position);
	}
	free(my_clock);
}

void	dep_up(game_t *game)
{
	float x = game->perso->position.x;
	float y = game->perso->position.y;
	my_clock_t *my_clock = init_linked_clock();

	if (game->perso->y != 0 && detect_col(game, 11) != -1) {
		game->perso->mouvement.y = 1;
		game->perso->mouvement.x = 0;
		while (game->perso->position.x > x - 36.4 && game->perso->position.y > y - 13.4) {
			loop_move(my_clock, game->perso, game->win);
			display(game, NULL, NULL);
		}
		game->perso->y -= 1;
		game->perso->position.x = game->map->iso[game->perso->x][game->perso->y].x - 10;
		game->perso->position.y = game->map->iso[game->perso->x][game->perso->y].y - 27;
		game->perso->mouvement.y = 0;
		sfSprite_setPosition(game->perso->sprite, game->perso->position);
	}
	free(my_clock);
}
