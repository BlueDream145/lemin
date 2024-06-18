/*
** EPITECH PROJECT, 2018
** get.c
** File description:
** get
*/

#include "lemin.h"

struct cell *get_cell_by_state(struct engine *engine, int start, int end)
{
	for (int i = 0; i < engine->cell_len; i++)
		if ((start == 1 && engine->cells[i]->start == 1) ||
			(end == 1 && engine->cells[i]->end == 1))
			return (engine->cells[i]);
	return (NULL);
}

struct cell *get_cell_by_id(struct engine *engine, int id)
{
	for (int i = 0; i < engine->cell_len; i++)
		if (engine->cells[i]->id == id)
			return (engine->cells[i]);
	return (NULL);
}

struct cell *get_cell_by_coordinates(struct engine *engine, int x, int y)
{
	for (int i = 0; i < engine->cell_len; i++)
		if (engine->cells[i]->x == x &&
			engine->cells[i]->y == y)
			return (engine->cells[i]);
	return (NULL);
}

struct cell *get_direction_by_id(struct cell *cell, int direction_id)
{
	for (int i = 0; i < cell->len; i++)
		if (cell->access_cells[i]->id == direction_id)
			return (cell->access_cells[i]);
	return (NULL);
}

int get_cells_len(char *str)
{
	char *tmp = get_line(str, 0);
	int i = my_strlen(tmp) + 1;
	int len = 0;

	while (tmp != NULL) {
		if (line_type(tmp) == CELL)
			len++;
		tmp = get_line(str, i);
		if (tmp != NULL)
			i += my_strlen(tmp) + 1;
	}
	return (len);
}