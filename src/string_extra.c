/*
** EPITECH PROJECT, 2018
** string_extra.c
** File description:
** String manipulation
*/

#include "lemin.h"

char **my_str_to_word_array(const char *str, char separator)
{
	char **result = malloc(sizeof(char *) * my_strlen(str));
	char *content = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (result == NULL || content == NULL || my_strlen(str) == 0)
		return (NULL);
	split_string(str, separator, result, content);
	return (result);
}

void split_string(const char *str, char separator,
	char **result, char *content)
{
	int j = 0;
	int k = 0;

	for (int i = 0; i < my_strlen(str) + 1; i++) {
		if (str[i] != separator) {
			content[j] = str[i];
			j++;
			content[j] = '\0';
		} else if (my_strlen(content) > 0) {
			j = 0;
			result[k] = my_strdup(content);
			k++;
		}
	}
	if (my_strlen(content) > 0) {
		j++;
		content[j] = '\0';
		result[k] = my_strdup(content);
		k++;
	}
	result[k] = '\0';
}

int string_len(char *src, char find)
{
	int len = 0;

	for (int i = 0; src[i]; i++)
		if (src[i] == find)
			len++;
	return (len);
}