/*
** EPITECH PROJECT, 2017
** pause
** File description:
** pause
*/

#include <stdbool.h>
#include "game.h"

bool      loop_pause(game_t *game)
{
          bool is_pause = true;
          pause_t *pause = game->pause;

          pause->pos_pause.x = 0;
          pause->pos_pause.y = 0;
          sfSprite_setPosition(pause->pause, pause->pos_pause);
          while (is_pause == true && sfRenderWindow_isOpen(game->win->window)) {
                    while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
                              if (sfKeyboard_isKeyPressed(sfKeyP))
                                        return (false);
                              if (sfKeyboard_isKeyPressed(sfKeyE))
                                        return (true);
                    }
                    sfRenderWindow_clear(game->win->window, sfBlack);
                    display_pause(game);
                    sfRenderWindow_display(game->win->window);
          }
          return (false);
}
