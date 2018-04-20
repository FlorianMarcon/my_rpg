/*
** EPITECH PROJECT, 2018
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include "game.h"

Test(is_extension, test1)
{
	cr_assert_eq(is_extension("object.map", "map"), 1);
	cr_assert_eq(is_extension("ect", "object"), 0);
	cr_assert_eq(is_extension(NULL, "a"), 0);
	cr_assert_eq(is_extension("aa", NULL), 0);
}
