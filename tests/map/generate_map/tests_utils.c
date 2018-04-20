/*
** EPITECH PROJECT, 2017
** tests
** File description:
** tests
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "map.h"

Test(fill_setting, test1)
{
	int fd = open("./data/fill_setting", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_setting(fd, &map), 0);
	cr_assert_eq(fill_setting(fd, &map), 1);
	cr_assert_eq(fill_setting(98, &map), 1);
	close(fd);
}

Test(fill_path_sprite, test1)
{
	int fd = open("./data/fill_path_sprite", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_path_sprite(fd, &map), 0);
	close(fd);
	cr_assert_eq(fill_path_sprite(98, &map), 1);
	fd = open("./data/fill_setting", O_RDONLY);
	cr_assert_eq(fill_path_sprite(fd, &map), 1);
	close(fd);
}

Test(generate_map, test1)
{
	cr_assert_neq(generate_map("./data/base.map"), NULL);
	cr_assert_eq(generate_map("./data/false_path"), NULL);
	cr_assert_eq(generate_map("./data/fill_setting"), NULL);
}
