/*
** EPITECH PROJECT, 2018
** output.c
** File description:
** Put str
*/

#include "lemin.h"

void my_put_char(char c)
{
	write(1, &c, 1);
}

void my_put_str(const char *str)
{
	for (int i = 0; str[i]; i++)
		write(1, &str[i], 1);
}

void my_put_error(const char *str)
{
	for (int i = 0; str[i]; i++)
		write(2, &str[i], 1);
}

int my_put_nbr(int nb)
{
	if (nb > 9)
		my_put_nbr(nb / 10);
	else if (nb < 0) {
		nb = nb * -1;
		write(1, "-", 1);
		my_put_nbr(nb / 10);
	}
	my_put_char(nb % 10 + '0');
	return (0);
}