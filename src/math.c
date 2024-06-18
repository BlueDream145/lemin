/*
** EPITECH PROJECT, 2018
** math.c
** File description:
** Find nearest path
*/

#include "lemin.h"

struct cell *get_nearest_cell(struct engine *engine, struct cell *start,
	struct cell *end)
{
	struct cell *dest = NULL;
	int max_distance = 2147483647;

	for (int i = 0; i < start->len; i++) {
		if (cell_empty(engine, start->access_cells[i]->id, end) == 0)
			continue;
		if (start->access_cells[i]->id == end->id)
			return (start->access_cells[i]);
		if (manhattan_distance(start->access_cells[i], end)
			< max_distance) {
			max_distance =
			manhattan_distance(start->access_cells[i], end);
			dest = start->access_cells[i];
		}
	}
	return (dest);
}

int manhattan_distance(struct cell *start, struct cell *end)
{
	int hor = (end->x - start->x) * (end->x - start->x);
	int ver = (end->y - start->y) * (end->y - start->y);

	return (hor + ver);
}

int cell_empty(struct engine *engine, int cell_id, struct cell *end)
{
	if (cell_id == end->id)
		return (1);
	for (int i = 0; i < engine->entity_len; i++) {
		if (engine->entities[i]->started == 0 ||
			engine->entities[i]->finished == 1)
			continue;
		if (engine->entities[i]->cell_id == cell_id)
			return (0);
	}
	return (1);
}