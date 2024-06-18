/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include "lemin.h"

int main(int ac, char **as)
{
	struct engine *engine = get_instance();
	char *content = read_file();
	int callback;

	if (ac != 1 || engine == NULL || content == NULL ||
		check_file(content) == 0 || as == NULL
		|| serialize_instance(engine, content) == 0)
		return (EXIT_FAIL);
	callback = process(engine);
	free_instance(engine);
	return (callback);
}
