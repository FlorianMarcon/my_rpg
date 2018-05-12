/*
** EPITECH PROJECT, 2017
** status_quete
** File description:
** status_quete
*/

#include "quete.h"
#include "game.h"

void	quete_give_all_object(quete_t *quete, game_t *game)
{
	linked_list_t *list = quete->obj_given;
	player_inv_t *ply = game->list_inv_player;
	toto_t *toto;

	while (list != NULL) {
		toto = (toto_t *)list->data;
		if (toto != NULL)
			for (int i = 0; i != toto->quantity; i++)
				ply = create_obj_in_inv(game->list_inventory,\
				toto->name, ply);
		list = list->next;
	}
	game->list_inv_player = ply;
}
void	delete_obj_needed_for_quete(quete_t *quete, game_t *game)
{
	linked_list_t *list = quete->obj_need;
	player_inv_t *l_inv = game->list_inv_player;
	toto_t *toto;

	while (list != NULL) {
		toto = (toto_t *)list->data;
		if (toto != NULL) {
			for (int i = toto->quantity; i != 0; i--)
				l_inv = delete_obj_in_inv(toto->name,
							l_inv);
		}
		list = list->next;
	}
	game->list_inv_player = l_inv;
}
bool	is_present(toto_t *toto, player_inv_t *list)
{
	char *need = toto->name;
	int quant = toto->quantity;

	while (list != NULL) {
		if (my_strcmp(need, list->name) == 0 &&\
		list->quantity == quant)
			return (true);
		list = list->next;
	}
	return (false);
}
bool	status_quete(quete_t *quete, game_t *game)
{
	linked_list_t *needed = quete->obj_need;
	toto_t *toto;

	if (quete->validated == true)
		return (true);
	while (needed != NULL) {
		toto = (toto_t *)needed->data;
		if (toto != NULL && is_present(toto,\
		game->list_inv_player) == false) {
			return (false);
		}
		needed = needed->next;
	}
	delete_obj_needed_for_quete(quete, game);
	quete_give_all_object(quete, game);
	return (true);
}
