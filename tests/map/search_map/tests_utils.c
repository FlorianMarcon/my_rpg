/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "map.h"

Test(search_map, test1)
{
	linked_list_t *list = generate_list_map("./data/map/");
	map_t *map = NULL;

	cr_assert_neq(list, NULL);
	map = search_map(list, 2);
	cr_assert_neq(map, NULL);
	map = search_map(list, 678);
	cr_assert_eq(map, NULL);
}
