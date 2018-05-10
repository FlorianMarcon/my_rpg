/*
** EPITECH PROJECT, 2017
** status_quete
** File description:
** status_quete
*/

#include "quete.h"
#include "game.h"

void      quete_give_all_object(quete_t *quete, game_t *game)
{
          linked_list_t *list = quete->obj_given;
	player_inv_t *ply = game->list_inv_player;
	char *str = NULL;

          while (list != NULL) {
		str = (char *)list->data;
		if (str != NULL)
			ply = create_obj_in_inv(game->list_inventory, str, ply);
		list = list->next;
	}
	game->list_inv_player = ply;
}
void      delete_obj_needed_for_quete(quete_t *quete, game_t *game)
{
          linked_list_t *list = quete->obj_need;
          player_inv_t *l_inv = game->list_inv_player;
          char *str = NULL;

          while (list != NULL) {
                    str = (char *)list->data;
                    if (str != NULL)
                              l_inv = delete_obj_in_inv(str, l_inv);
                    list = list->next;
          }
          game->list_inv_player = l_inv;
}
bool	is_present(char *need, player_inv_t *list)
{
	while (list != NULL) {
		if (strcmp(need, list->type) == 0 && list->status == false) {
                              list->status = true;
                              return (true);
                    }
		list = list->next;
	}
	return (false);
}
void      reset_list_inv(player_inv_t *list)
{
          while (list != NULL) {
                    list->status = false;
                    list = list->next;
          }
}
bool	status_quete(quete_t *quete, game_t *game)
{
	linked_list_t *needed = quete->obj_need;
	char *str = NULL;

	if (quete->validated == true)
		return (true);
	while (needed != NULL) {
		str = (char *)needed->data;
		if (str != NULL && is_present(str, game->list_inv_player) == false) {
                              reset_list_inv(game->list_inv_player);
                    	return (false);
                    }
		needed = needed->next;
	}
          delete_obj_needed_for_quete(quete, game);
	quete_give_all_object(quete, game);
          reset_list_inv(game->list_inv_player);
	return (true);
}
