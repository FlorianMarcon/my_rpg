/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** window
*/

#include "game.h"
#include "graphique.h"

param_t	*gp()
{
	static param_t *var;
	static int ps = 0;

	if (ps == 0) {
		ps = 1;
		var->win = generate_window(1200, 800, 32);
		var->perso = create_my_perso();
		var->list = generate_list_map("./map/");
		var->map = (map_t *)var->list->next->data;
	}
	return (var);
}

void	affect_move_perso(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		dep_up(game);
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		dep_down(game);
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		dep_left(game);
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		dep_right(game);
}

/*int	main()
{
	window_t *win = generate_window(1200, 800, 32);
	perso_t *my_perso = create_my_perso();
	linked_list_t *list = generate_list_map("./map/");
	map_t *map = (map_t *)list->next->data;

	my_perso->position.x = map->iso[0][0].x - 27;
	my_perso->position.y = map->iso[0][0].y - 32;
	sfSprite_setPosition(my_perso->sprite, my_perso->position);
	while (sfRenderWindow_isOpen(win->window)) {
		while (sfRenderWindow_pollEvent(win->window, &win->event)) {
			if (win->event.type == sfEvtClosed)
				sfRenderWindow_close(win->window);
			affect_move_perso(perso, win, map);
		}
		sfRenderWindow_clear(win->window, sfWhite);
		display_map(map, win);
		sfRenderWindow_drawSprite(win->window, my_perso->sprite, NULL);
		sfRenderWindow_display(win->window);
	}
	sfRenderWindow_destroy(win->window);
	free(win);
	free(my_perso);
	free (list);
	free (map);
}

//sfRenderWindow_drawSprite(window->window, obj->sprite, NULL);
*/
