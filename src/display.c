/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** Display file content
*/

#include "lemin.h"

void display_file(char *content)
{
	char *line = get_line(content, 0);
	int pos = 0;

	while (line != NULL) {
		pos += my_strlen(line) + 1;
		display_line(line, pos);
		if (line_type(line) == COMMENT && string_len(line, '#') != 2) {
			line = get_line(content, pos);
			continue;
		}
		my_put_str(line);
		my_put_char('\n');
		line = get_line(content, pos);
	}
}

void display_line(char *line, int pos)
{
	static int tunnel = 0;
	static int cell = 0;

	if (pos < 0)
		return;
	if (line_type(line) == UNKNOWN && my_getnbr(line) > 0) {
		my_put_str("#number_of_ants\n");
	}
	if (line_type(line) == DIRECTION && tunnel == 0) {
		tunnel = 1;
		my_put_str("#tunnels\n");
	}
	if ((line_type(line) == CELL || (line_type(line) == COMMENT
		&& my_strcmp(line, "##start") == 0)
		|| (line_type(line) == COMMENT &&
		my_strcmp(line, "##end") == 0)) && cell == 0) {
		cell = 1;
		my_put_str("#rooms\n");
	}
}