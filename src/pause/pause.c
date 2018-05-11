/*
** EPITECH PROJECT, 2017
** pause
** File description:
** pause
*/

#include <stdbool.h>
#include "game.h"

int    event_pause(game_t *game)
{
        while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
                if (sfKeyboard_isKeyPressed(sfKeyP))
                        return (2);
                if (sfKeyboard_isKeyPressed(sfKeyE))
                        return (1);
        }
        return (0);

}

bool      loop_pause(game_t *game)
{
          bool is_pause = true;
          pause_t *pause = game->pause;

          pause->pos_pause.x = 0;
          pause->pos_pause.y = 0;
          sfSprite_setPosition(pause->pause, pause->pos_pause);
          while (is_pause == true && sfRenderWindow_isOpen(game->win->window)) {
                  if (event_pause(game) == 1)
                        return (true);
                else if (event_pause(game) == 2)
                        return (false);
                    sfRenderWindow_clear(game->win->window, sfBlack);
                    display_pause(game);
                    sfRenderWindow_display(game->win->window);
          }
          return (false);
}
