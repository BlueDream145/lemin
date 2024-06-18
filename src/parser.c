/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** Parse file and serialize data in engine
*/

#include "lemin.h"

int parse_file(struct engine *engine)
{
	char *tmp = get_line(engine->file_content, 0);
	char *last = NULL;
	int i = my_strlen(tmp) + 1;

	engine->cells = malloc(sizeof(struct cell*) *
		get_cells_len(engine->file_content));
	if (engine->cells == NULL)
		return (0);
	while (tmp != NULL) {
		if (line_type(tmp) == UNKNOWN && my_getnbr(tmp) > 0 &&
			engine->total_entities != 0)
			return (0);
		if (parse_line(engine, tmp, last) == 0)
			return (0);
		last = my_strdup(tmp);
		tmp = get_line(engine->file_content, i);
		if (tmp != NULL)
			i += my_strlen(tmp) + 1;
	}
	free(tmp);
	return (1);
}

int parse_line(struct engine *engine, char *line, char *last)
{
	if (line_type(line) == UNKNOWN && my_getnbr(line) > 0) {
		engine->total_entities = my_getnbr(line);
		return (1);
	}
	switch (line_type(line)) {
		case COMMENT:
			return (1);
		case CELL:
			return (parse_cell(engine,
				my_str_to_word_array(line, ' '), last));
			break;
		case DIRECTION:
			return (parse_direction(engine,
				my_str_to_word_array(line, '-')));
			break;
		case UNKNOWN:
			return (0);
	}
	return (1);
}

int parse_cell(struct engine *engine, char **src, char *last)
{
	struct cell *cell = malloc(sizeof(struct cell));

	cell->access_cells = malloc(sizeof(struct cell*) *
		get_cells_len(engine->file_content));
	if (cell == NULL || cell->access_cells == NULL)
		return (0);
	cell->id = my_getnbr(src[0]);
	cell->x = my_getnbr(src[1]);
	cell->y = my_getnbr(src[2]);
	cell->len = 0;
	if (last != NULL && my_strcmp(last, "##start") == 0)
		cell->start = 1;
	else
		cell->start = 0;
	if (last != NULL && my_strcmp(last, "##end") == 0)
		cell->end = 1;
	else
		cell->end = 0;
	return (insert_cell(engine, cell));
}

int parse_direction(struct engine *engine, char** src)
{
	int cell_id_first = my_getnbr(src[0]);
	int cell_id_scd = my_getnbr(src[1]);

	for (int i = 0; i < engine->cell_len; i++) {
		if (engine->cells[i]->id == cell_id_first
			&& insert_direction(engine, cell_id_first,
			get_cell_by_id(engine, cell_id_scd)) == 0)
				return (0);
	}
	return (1);
}

int line_type(char *line)
{
	for (int i = 0; line[i]; i++) {
		if (line[i] == '#')
			return (COMMENT);
		if (line[i] == ' ')
			return (CELL);
		if (line[i] == '-')
			return (DIRECTION);
	}
	return (UNKNOWN);
}