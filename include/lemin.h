/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef LEMIN_
	#define LEMIN_

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>

	#define EXIT_NORMAL 0
	#define EXIT_FAIL 84

struct engine {
	char *file_content;
	struct entity **entities;
	struct cell **cells;
	int entity_len;
	int cell_len;
	int total_entities;
	int callback;
};

struct cell {
	struct cell **access_cells;
	int len;
	int id;
	int x;
	int y;
	int start;
	int end;
};

struct entity {
	int cell_id;
	int x;
	int y;
	int started;
	int finished;
};

struct buff {
	int *buffer;
	int pos;
};

enum line_type {
	COMMENT,
	CELL,
	DIRECTION,
	UNKNOWN
};

// check.c
int check_file(char *content);
int check_syntax(char *content, int start, int end);
int check_line(struct buff *buff, char *line);
int check_cell(struct buff *buff, char *line);
int check_direction(struct buff *buff, char *line);

// display.c
void display_file(char *content);
void display_line(char *line, int pos);

// engine.c
int process(struct engine *engine);
void process_move(struct engine *engine);
void find_path(struct engine *engine, struct entity *entity);
void display_step(struct engine *engine);
int finished(struct engine *engine);

// get.c
struct cell *get_cell_by_state(struct engine *engine, int start, int end);
struct cell *get_cell_by_id(struct engine *engine, int id);
struct cell *get_cell_by_coordinates(struct engine *engine, int x, int y);
struct cell *get_direction_by_id(struct cell *cell, int direction_id);
int get_cells_len(char *str);

// insert.c
int insert_direction(struct engine *engine,
	int id, struct cell *direction);
int insert_cell(struct engine *engine, struct cell *cell);
int insert_entity(struct engine *engine);

// instances.c
struct engine *get_instance(void);
struct buff *get_buffer(int len);
int serialize_instance(struct engine *engine, char *content);
void insert_first_entities(struct cell *start, struct engine *eng);
void free_instance(struct engine *engine);

// math.c
struct cell *get_nearest_cell(struct engine *engine, struct cell *start,
	struct cell *end);
int manhattan_distance(struct cell *start, struct cell *end);
int cell_empty(struct engine *engine, int cell_id, struct cell *end);

// output.c
void my_put_char(char c);
void my_put_str(const char *str);
void my_put_error(const char *str);
int my_put_nbr(int nb);

// parser.c
int parse_file(struct engine *engine);
int parse_line(struct engine *engine, char *line, char *last);
int parse_cell(struct engine *engine, char **src, char *last);
int parse_direction(struct engine *engine, char**src);
int line_type(char *line);

// reader.c
char *read_file(void);
char *get_line(char *str, int start);
int my_getnbr(char *str);
int array_contain(int *array, int value, int len);

// string_extra.c
void my_put_str(const char *str);
char **my_str_to_word_array(const char *str, char separator);
void split_string(const char *str, char separator,
	char **result, char *content);
int string_len(char *src, char find);

// string.c
char *my_strdup(const char *src);
char *my_strcpy(char *dest, const char *src);
int my_strlen(const char *src);
int my_strcmp(const char *s1, const char *s2);

#endif /* LEMIN */