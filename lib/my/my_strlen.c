/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** For lib
*/

#include <unistd.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (;str[i] != '\0'; ++i);
	return (i);
}