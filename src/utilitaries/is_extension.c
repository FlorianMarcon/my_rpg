/*
** EPITECH PROJECT, 2017
** is_extension
** File description:
** is_extension
*/

#include "my.h"

int	is_extension(char *str, char *ext)
{
	int i;
	int o;

	if (str == NULL || ext == NULL)
		return (0);
	i = my_strlen(str) - 1;
	o = my_strlen(ext) - 1;
	while (i != -1 && o != -1) {
		if (str[i--] != ext[o--])
			return (0);
	}
	if (o != -1)
		return (0);
	else
		return (1);
}
