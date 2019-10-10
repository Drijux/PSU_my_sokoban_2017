/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** For lib: function for cpy string and malloc here
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
	char *dest = "";

	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	my_strcpy(dest, src);
	return (dest);
}