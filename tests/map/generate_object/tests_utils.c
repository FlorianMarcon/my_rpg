/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"

Test(generate_object, test1)
{
	object_t *obj;

	obj = generate_object("./data/box.object");
	cr_assert_neq(obj, NULL);
	cr_assert_neq(obj->name, NULL);
	cr_assert_neq(obj->texture, NULL);
	cr_assert_neq(obj->rect, NULL);
	cr_assert_eq(obj->max_rect, 3);
	cr_assert_eq(obj->number, 20);
}
