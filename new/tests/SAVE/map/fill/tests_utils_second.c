/*
** EPITECH PROJECT, 2017
** tests_utils
** File description:
** tests_utils
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "map.h"

Test(fill_setting, test1)
{
	int fd = open("./data/fill_setting_success", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_setting(&map, fd), 0);
	cr_assert_eq(map.width, 1);
	cr_assert_eq(map.height, 2);
	cr_assert_eq(map.number, 3);
	close(fd);
}

Test(fill_setting, fail)
{
	int fd = open("./data/fill_setting_fail", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_setting(&map, fd), 1);
	cr_assert_eq(fill_setting(&map, fd), 1);
	close(fd);
}

Test(fill_map, success)
{
	int fd = open("./data/fill_map_success", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_setting(&map, fd), 0);
	cr_assert_eq(fill_map(&map, fd), 0);
	cr_assert_eq(map.map[0][0], 1);
	cr_assert_eq(map.map[1][4], 1);
	cr_assert_eq(map.map[4][4], 5);
	close(fd);
}
Test(fill_map, fail)
{
	int fd = open("./data/fill_map_fail", O_RDONLY);
	map_t map;

	cr_assert_neq(fd, -1);
	cr_assert_eq(fill_setting(&map, fd), 0);
	cr_assert_eq(fill_map(&map, fd), 1);
	close(fd);
}
