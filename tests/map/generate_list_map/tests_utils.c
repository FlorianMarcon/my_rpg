/*
** EPITECH PROJECT, 2017
** generate_list_map
** File description:
** generate_list_map
*/

#include <criterion/criterion.h>
#include "my.h"
#include "map.h"

Test(generate_list_map, test1)
{
	linked_list_t *list = generate_list_map("./data/");

	cr_assert_neq(list, NULL);
	cr_assert_eq(list->next, NULL);

}
