/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** scene
*/

#include "fight.h"
#include "graphique.h"
#include "game.h"

void	next_set_scene(scene_t *scene)
{
	sfText_setColor(scene->survol_attack, sfCyan);
	sfText_setColor(scene->survol_magic, sfCyan);
	sfText_setColor(scene->dead, sfRed);
	sfText_setColor(scene->you_won, sfYellow);
	sfText_setCharacterSize(scene->dead, 150);
	sfText_setCharacterSize(scene->you_won, 100);
	sfSprite_setTexture(scene->sprite_battleground, scene->battleground, sfTrue);
	sfSprite_setTexture(scene->sprite_barre, scene->textu_barre, sfTrue);
	sfSprite_setOrigin(scene->sprite_barre, scene->origi_barre);
	sfSprite_setPosition(scene->sprite_barre, scene->pos_barre);
	scene->real_pos_attack = sfText_getGlobalBounds(scene->attack);
	scene->real_pos_magic = sfText_getGlobalBounds(scene->magic);
}

void	set_scene(scene_t *scene)
{
	sfText_setString(scene->attack, "Attack");
	sfText_setString(scene->survol_attack, "Attack");
	sfText_setString(scene->life, scene->life_tab);
	sfText_setString(scene->dead, "You are dead . . .");
	sfText_setString(scene->you_won, "You won !");
	sfText_setFont(scene->attack, scene->font);
	sfText_setFont(scene->survol_attack, scene->font);
	sfText_setFont(scene->char_name, scene->font);
	sfText_setFont(scene->life, scene->font);
	sfText_setFont(scene->dead, scene->font);
	sfText_setFont(scene->you_won, scene->font);
	sfText_setPosition(scene->attack, scene->pos_attack);
	sfText_setPosition(scene->survol_attack, scene->pos_attack);
	sfText_setPosition(scene->char_name, scene->pos_name);
	sfText_setPosition(scene->life, scene->pos_life);
	sfText_setOrigin(scene->dead, scene->origi_dead);
	sfText_setPosition(scene->dead, scene->pos_dead);
	sfText_setPosition(scene->you_won, scene->pos_you_won);
	next_set_scene(scene);
}

void	next_init_scene(scene_t *scene)
{
	scene->battleground = sfTexture_createFromFile("src/img_fight/last_resize_background_clean.png", NULL);
	scene->textu_barre = sfTexture_createFromFile("src/img_fight/ff6_barre_export.jpg", NULL);
	scene->sprite_battleground = sfSprite_create();
	scene->sprite_barre = sfSprite_create();
	sfText_setString(scene->magic, "Magic");
	sfText_setString(scene->survol_magic, "Magic");
	scene->pos_magic = (sfVector2f){360, 920};
	sfText_setPosition(scene->magic, scene->pos_magic);
	sfText_setPosition(scene->survol_magic, scene->pos_magic);
	sfText_setFont(scene->magic, scene->font);
	sfText_setFont(scene->survol_magic, scene->font);
	set_scene(scene);
}

void	init_scene(scene_t *scene, game_t *game)
{
	scene->font = sfFont_createFromFile("font/attack_of_the_cucumbers.ttf");
	scene->attack = sfText_create();
	scene->survol_attack = sfText_create();
	scene->char_name = sfText_create();
	sfText_setString(scene->char_name, game->perso->name);
	scene->life = sfText_create();
	scene->dead = sfText_create();
	scene->magic = sfText_create();
	scene->survol_magic = sfText_create();
	scene->you_won = sfText_create();
	scene->pos_attack = (sfVector2f){360, 870};
	scene->pos_name = (sfVector2f){600, 870};
	scene->pos_dead = (sfVector2f){640, 300};
	scene->origi_dead = (sfVector2f){563, 55};
	scene->pos_you_won = (sfVector2f){400, 200};
	scene->pos_life = (sfVector2f){800, 870};
	scene->origi_barre = (sfVector2f){309, 73};
	scene->pos_barre = (sfVector2f){640, 926};
	scene->life_tab = get_nb_in_char(game->perso->stat.vie_c);
	next_init_scene(scene);
}

void	launch_fight(game_t *game)
{
	scene_t scene;
	int is_fight = 1;

	init_scene(&scene, game);
	while (is_fight == 1) {
		while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
			if (game->win->event.type == sfEvtClosed)
				sfRenderWindow_close(game->win->window);
			sfRenderWindow_clear(game->win->window, sfBlack);
			sfRenderWindow_drawSprite(game->win->window, scene.sprite_battleground, NULL);
			sfRenderWindow_drawSprite(game->win->window, scene.sprite_barre, NULL);
			if (sfFloatRect_contains(&scene.real_pos_attack, game->win->event.mouseMove.x, game->win->event.mouseMove.y))
				sfRenderWindow_drawText(game->win->window, scene.survol_attack, NULL);
			if (sfFloatRect_contains(&scene.real_pos_magic, game->win->event.mouseMove.x, game->win->event.mouseMove.y))
				sfRenderWindow_drawText(game->win->window, scene.survol_magic, NULL);
			sfRenderWindow_drawText(game->win->window, scene.attack, NULL);
			sfRenderWindow_drawText(game->win->window, scene.char_name, NULL);
			sfRenderWindow_drawText(game->win->window, scene.life, NULL);
			sfRenderWindow_drawText(game->win->window, scene.magic, NULL);
			sfRenderWindow_display(game->win->window);
		}
	}

}