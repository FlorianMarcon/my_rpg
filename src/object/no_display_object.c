/*
** EPITECH PROJECT, 2017
** no_display_object
** File description:
** no_display_object
*/

#include "map.h"

void      no_display_object(linked_list_t *list, unsigned int x, unsigned int y)
{
          sprite_t *spr;

          while (list != NULL) {
                    spr = list->data;
                    if (spr != NULL && spr->x == x && spr->y == y) {
                              spr->displaying = false;
                              return;
                    }
                    list = list->next;
          }
}
