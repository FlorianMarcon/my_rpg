/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include "map.h"
#include "my.h"

Test(generate_list_map, test1)
{
	linked_list_t *list = generate_list_map("../map/");
	int i = 0;

	cr_assert_neq(list, NULL);
	while (list != NULL) {
		list = list->next;
		i++;
	}
	cr_assert(i > 2);
}
