/*
** EPITECH PROJECT, 2017
** search_obj_inv_player
** File description:
** search_obj_inv_player
*/

#include "inventory.h"

player_inv_t        *search_obj_inv_player(char *name, player_inv_t *list)
{
          while (list != NULL) {
                    if (strcmp(list->name, name) == 0)
                              return (list);
                    list = list->next;
          }
          return (NULL);
}
