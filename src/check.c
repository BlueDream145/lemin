/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** Check if file exists and his all content
*/

#include "lemin.h"

int check_file(char *content)
{
	if (content == NULL)
		return (0);
	if (string_len(content, '\n') <= 2 || my_strlen(content) < 6)
		return (0);
	if (check_syntax(content, 0, 0) == 0)
		return (0);
	return (1);
}

int check_syntax(char *content, int start, int end)
{
	struct buff *buff = get_buffer(string_len(content, '\n'));
	char *tmp = get_line(content, 0);
	int i = 0;

	while (tmp != NULL && my_strlen(tmp) != 0) {
		if (tmp != NULL)
			i += my_strlen(tmp) + 1;
		if ((check_line(buff, tmp)) == -1)
			return (0);
		if (line_type(tmp) == COMMENT
			&& my_strcmp(tmp, "##start") == 0)
			start = 1;
		if (line_type(tmp) == COMMENT
			&& my_strcmp(tmp, "##end") == 0)
			end = 1;
		tmp = get_line(content, i);
	}
	if (start == 0 || end == 0)
		return (0);
	free(tmp);
	return (1);
}

int check_line(struct buff *buff, char *line)
{
	if (line_type(line) == UNKNOWN && my_getnbr(line) > 0)
		return (1);
	if (line_type(line) == UNKNOWN)
		return (-1);
	if (line_type(line) == CELL &&
		check_cell(buff, line) == 0)
		return (-1);
	if (line_type(line) == DIRECTION
		&& check_direction(buff, line) == 0)
		return (-1);
	return (1);
}

int check_cell(struct buff *buff, char *line)
{
	char **src = NULL;
	int i;

	if (string_len(line, ' ') != 2)
		return (0);
	src = my_str_to_word_array(line, ' ');
	if (src == NULL || !src[0] || !src[1] || !src[2])
		return (0);
	for (i = 0; i < 3; i++)
		if (my_getnbr(src[i]) < 0)
			return (0);
	if (i != 3 || array_contain(buff->buffer,
		my_getnbr(src[0]), buff->pos) == 1)
		return (0);
	buff->buffer[buff->pos] = my_getnbr(src[0]);
	buff->pos++;
	free(src);
	return (1);
}

int check_direction(struct buff *buff, char *line)
{
	char **src = NULL;
	int i;

	if (string_len(line, '-') != 1 ||
		buff->buffer == NULL || buff->pos == 0)
		return (0);
	src = my_str_to_word_array(line, '-');
	if (src == NULL || !src[0] || !src[1])
		return (0);
	for (i = 0; i < 2; i++)
		if (my_getnbr(src[i]) < 0)
			return (0);
	if (i != 2 || array_contain(buff->buffer,
		my_getnbr(src[0]), buff->pos) == 0
		|| array_contain(buff->buffer,
		my_getnbr(src[1]), buff->pos) == 0)
		return (0);
	free(src);
	return (1);
}