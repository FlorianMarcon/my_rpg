/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** get_nb_in_char
*/

#include "game.h"

int	how_malloc(float n)
{
	int m = 0;

	while (n >= 1) {
		n = n / 10;
		m++;
	}
	return (m);
}

float	reduce(float n)
{
	while (n >= 1)
		n = n / 10;
	return (n);
}

char	*transform(int nb)
{
	char *str;
	float n = nb;
	int m = how_malloc(n);
	int i = -1;
	int f = 0;

	if ((str = malloc(m + 1)) == NULL)
		return (NULL);
	n = reduce(n);
	while (m != 0) {
		n *= 10;
		f = n;
		str[++i] = f + '0';
		n -= f;
		m--;
	}
	str[++i] = '\0';
	return (str);
}

char	*get_nb_in_char(int nb)
{
	char *str;

	if (nb < 10) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0' + nb;
		str[1] = '\0';
	} else {
		str = transform(nb);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}
