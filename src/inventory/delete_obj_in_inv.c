/*
** EPITECH PROJECT, 2017
** delete_obj_in_inv
** File description:
** delete_obj_in_inv
*/

#include "inventory.h"

player_inv_t	*delete_obj_in_inv(char *name, player_inv_t *list)
{
          player_inv_t *obj = search_obj_inv_player(name, list);
          player_inv_t *re = list;

          if (obj == NULL)
                    return (list);
          if (obj->quantity > 1) {
                    obj->quantity--;
                    return (list);
          }
          if (obj == list) {
                    list = list->next;
          } else {
                    while (re->next != obj)
                              re = re->next;
                    re->next = re->next->next;
          }
          free(obj);
          return (list);
}
