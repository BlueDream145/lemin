/*
** EPITECH PROJECT, 2018
** reader.c
** File description:
** Read functions
*/

#include "lemin.h"

char *read_file(void)
{
	char *buff = malloc(sizeof(char) * 4096);
	int offset = 0;

	if (buff == NULL)
		return (NULL);
	while (read(0, buff + offset, 1) > 0 && offset < 4095)
		offset += 1;
	buff[offset] = '\0';
	return (buff);
}

char *get_line(char *str, int start)
{
	char *result;
	int i;
	int len = 0;

	for (i = start; i < my_strlen(str) && str[i] != '\n'; i++)
		len++;
	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 2));
	if (result == NULL)
		return (NULL);
	for (i = start; str[i] && str[i] != '\n'; i++)
		result[i - start] = str[i];
	result[i - start] = '\0';
	return (result);
}

int array_contain(int *array, int value, int len)
{
	for (int i = 0; i < len; i++)
		if (array[i] == value)
			return (1);
	return (0);
}

int my_getnbr(char *str)
{
	int val = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			val *= 10;
			val += *str - '0';
		} else
			return (-1);
		str++;
	}
	return (val);
}