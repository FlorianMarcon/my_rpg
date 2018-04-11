/*
** EPITECH PROJECT, 2017
** tests
** File description:
** test
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"

Test(fill_matter, success)
{
	int fd = open ("./data/fill_matter_success", O_RDONLY);
	map_t map;
	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_matter(&map, fd), 0);
	cr_assert_neq(map.state_floor, NULL);
	cr_assert_neq(map.state_bottom, NULL);
	close(fd);
}

Test(fill_matter, fail)
{
	int fd = open ("./data/fill_matter_fail", O_RDONLY);
	map_t map = {.state_floor = NULL, .state_bottom = NULL};
	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_matter(&map, fd), 1);
	cr_assert_eq(map.state_floor, NULL);
	cr_assert_eq(map.state_bottom, NULL);
	close(fd);
}
Test(fill_matter, fail_two)
{
	int fd = open ("./data/fill_matter_fail_2", O_RDONLY);
	map_t map = {.state_floor = NULL, .state_bottom = NULL};
	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_matter(&map, fd), 1);
	cr_assert_eq(map.state_floor, NULL);
	cr_assert_eq(map.state_bottom, NULL);
	close(fd);
}

Test(fill_one_matter, test1)
{
	sfRenderStates *state;
	char *path = my_strdup("./matter/brown.jpg");

	state = fill_one_matter(path);
	cr_assert_neq(state->texture, NULL);
	cr_assert_neq(state, NULL);
	free(state);
	cr_assert_eq(fill_one_matter(NULL), NULL);
	cr_assert_eq(fill_one_matter("nimportequoi"), NULL);
}
