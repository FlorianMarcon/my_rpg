/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include "graphique.h"

Test(generate_sprite_from_file, test1)
{
	sfSprite *sprite = generate_sprite_from_file("../matter/background.jpg");

	cr_assert_neq(sprite, NULL);
}

Test(generate_sprite_from_file, test2)
{
	sfSprite *sprite = generate_sprite_from_file("pas_de_fichier.test");

	cr_assert_eq(sprite, NULL);
}
