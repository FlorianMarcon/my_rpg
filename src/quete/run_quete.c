/*
** EPITECH PROJECT, 2017
** run_quete
** File description:
** run_quete
*/

#include "quete.h"
#include "game.h"

quete_t	*search_quete(game_t *game, int id)
{
	linked_list_t *list = game->list_quete;
	quete_t *quete;

	while (list != NULL) {
		quete = (quete_t *)list->data;
		if (quete != NULL && quete->id == id)
			return (quete);
		list = list->next;
	}
	return (NULL);
}
void	active_message_quete(game_t *game, char **tab, unsigned int size)
{
	for (unsigned int i = 0; i != size; i++) {
		sfText_setString(game->text[i], tab[i]);
	}
	game->size_text = size;
}

void	run_quete(game_t *game, int id)
{
	quete_t *quete = search_quete(game, id);

	if (quete == NULL)
		return;
	quete->validated = status_quete(quete, game);
	if (quete->validated == true) {
		active_message_quete(game, quete->message_val, quete->size_message_val);
	} else
		active_message_quete(game, quete->message_no_val, quete->size_message_no_val);
	game->display_textbox = true;
}
