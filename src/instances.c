/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
** Manage engine instances
*/

#include "lemin.h"

struct engine *get_instance(void)
{
	struct engine *engine = malloc(sizeof(struct engine));

	if (engine == NULL)
		return (NULL);
	engine->callback = EXIT_NORMAL;
	engine->total_entities = 0;
	engine->entity_len = 0;
	engine->cell_len = 0;
	engine->cells = NULL;
	engine->entities = NULL;
	engine->file_content = NULL;
	return (engine);
}

struct buff *get_buffer(int len)
{
	struct buff *buff = malloc(sizeof(struct buff));

	if (buff == NULL)
		return (NULL);
	buff->buffer = malloc(sizeof(int) * len);
	if (buff->buffer == NULL)
		return (NULL);
	buff->pos = 0;
	return (buff);
}

int serialize_instance(struct engine *engine, char *content)
{
	engine->file_content = my_strdup(content);
	if (engine->file_content == NULL)
		return (0);
	return (parse_file(engine));
}

void insert_first_entities(struct cell *start, struct engine *eng)
{
	for (int i = 0; i < start->len && eng->total_entities >= 1; i++)
		insert_entity(eng);
}

void free_instance(struct engine *engine)
{
	if (engine->cells != NULL) {
		for (int i = 0; i < engine->cell_len; i++)
			free(engine->cells[i]->access_cells);
		free(engine->cells);
	}
	if (engine->entities != NULL)
		free(engine->entities);
	if (engine->file_content != NULL)
		free(engine->file_content);
	free(engine);
}