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
void	run_quete(game_t *game, int id)
{
	quete_t *quete = search_quete(game, id);

	if (quete == NULL)
		return;
	game->display_textbox = true;
	for (unsigned int i = 0; i != quete->size_message; i++) {
		sfText_setString(game->text[i], quete->message[i]);
	}
	game->size_text = quete->size_message;
}
