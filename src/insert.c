/*
** EPITECH PROJECT, 2018
** insert.c
** File description:
** insert
*/

#include "lemin.h"

int insert_entity(struct engine *engine)
{
	struct entity *entity = malloc(sizeof(struct entity));
	struct cell *cell = get_cell_by_state(engine, 1, 0);

	if (entity == NULL || cell == NULL)
		return (0);
	entity->cell_id = cell->id;
	entity->x = cell->x;
	entity->y = cell->y;
	entity->started = 1;
	entity->finished = 0;
	if (engine->entities == NULL)
		engine->entities = malloc(sizeof(struct entity*)
			* (engine->total_entities));
	if (engine->total_entities == 0 || engine->entities == NULL)
		return (0);
	engine->entities[engine->entity_len] = entity;
	engine->entity_len++;
	engine->total_entities--;
	return (1);
}

int insert_direction(struct engine *engine,
	int id, struct cell *direction)
{
	struct cell *cell = get_cell_by_id(engine, id);

	if (cell == NULL || get_direction_by_id(cell, direction->id) != NULL)
		return (0);
	cell->access_cells[cell->len] = direction;
	cell->len++;
	return (1);
}

int insert_cell(struct engine *engine, struct cell *cell)
{
	if (get_cell_by_id(engine, cell->id) != NULL ||
		get_cell_by_coordinates(engine, cell->x, cell->y) != NULL)
		return (0);
	engine->cells[engine->cell_len] = cell;
	engine->cell_len++;
	return (1);
}