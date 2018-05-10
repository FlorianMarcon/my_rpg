/*
** EPITECH PROJECT, 2017
** delete_obj_in_inv
** File description:
** delete_obj_in_inv
*/

#include "inventory.h"

player_inv_t	*delete_obj_in_inv(char *name, player_inv_t *list)
{
          player_inv_t *tmp = list;
          player_inv_t *re = list;

          while (tmp != NULL && strcmp(tmp->type, name) != 0)
                    tmp = tmp->next;
          if (tmp == NULL)
                    return (list);
          if (tmp == list) {
                    list = list->next;
          } else {
                    while (re->next != tmp)
                              re = re->next;
                    re->next = re->next->next;
          }
          free(tmp);
          return (list);
}
