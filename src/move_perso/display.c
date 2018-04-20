/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** display
*/

#include "game.h"

void	display_perso(perso_t *perso, window_t *win)
{
	sfRenderWindow_drawSprite(win->window, perso->sprite, NULL);
}

/*void	display_all(window_t *win, perso_t *perso, graph_map_t *map)
{
	sfRenderWindow_clear(win->window, sfWhite);
	display_map(map_graph, win, game->draw_line);
	display_perso(perso, win);
	sfRenderWindow_display(win->window);
}*/
