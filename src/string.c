/*
** EPITECH PROJECT, 2018
** string.c
** File description:
** String manipulation
*/

#include "lemin.h"

char *my_strdup(const char *src)
{
	char *str;
	int len = my_strlen(src) + 1;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = my_strcpy(str, src);
	return (str);
}

char *my_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int my_strlen(const char *src)
{
	int len = 0;

	for (len = 0; src[len]; len++);
	return (len);
}

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++);
	return (s1[i] - s2[i]);
}