/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
** Engine of program, find path
*/

#include "lemin.h"

int process(struct engine *eng)
{
	struct cell *start = get_cell_by_state(eng, 1, 0);
	struct cell *end = get_cell_by_state(eng, 0, 1);

	if (start == NULL || end == NULL)
		return (84);
	display_file(eng->file_content);
	my_put_str("#moves\n");
	for (int t = 0; eng->entity_len == 0 || finished(eng) != 0; t++) {
		if (t == 0)
			insert_first_entities(start, eng);
		else if (eng->total_entities >= 1)
			insert_entity(eng);
		if (t >= (eng->entity_len * eng->cell_len) * 3)
			return (EXIT_FAIL);
		process_move(eng);
		display_step(eng);
	}
	return (eng->callback);
}

void process_move(struct engine *engine)
{
	for (int i = 0; i < engine->entity_len; i++) {
		if (engine->entities[i]->started == 0 ||
			engine->entities[i]->finished == 1)
			continue;
		find_path(engine, engine->entities[i]);
	}
}

void find_path(struct engine *engine, struct entity *entity)
{
	struct cell *cell = get_cell_by_id(engine, entity->cell_id);
	struct cell *end_cell = get_cell_by_state(engine, 0, 1);
	struct cell *nearest_cell = NULL;

	if (cell == NULL || end_cell == NULL)
		return;
	if (cell->id == end_cell->id) {
		entity->finished = 1;
		entity->started = 0;
		return;
	}
	nearest_cell = get_nearest_cell(engine, cell, end_cell);
	if (nearest_cell == NULL)
		return;
	entity->cell_id = nearest_cell->id;
	entity->x = nearest_cell->x;
	entity->y = nearest_cell->y;
}

void display_step(struct engine *engine)
{
	int len = finished(engine);
	int current = 1;

	for (int i = 0; i < engine->entity_len; i++) {
		if (engine->entities[i]->finished == 1 ||
			engine->entities[i]->started == 0)
			continue;
		my_put_char('P');
		my_put_nbr(i + 1);
		my_put_char('-');
		my_put_nbr(engine->entities[i]->cell_id);
		if (current == len || len == 0)
			my_put_char('\n');
		else
			my_put_char(' ');
		current++;
	}
}

int finished(struct engine *engine)
{
	int len = 0;

	for (int i = 0; i < engine->entity_len; i++)
		if (engine->entities[i]->finished == 0)
			len++;
	return (len);
}