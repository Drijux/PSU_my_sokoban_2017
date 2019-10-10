/*
** EPITECH PROJECT, 2017
** my_file_linelen.c
** File description:
** For lib
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int my_file_linelen(const char *pathname)
{
    FILE *file = fopen(pathname, "r");
    int nb = 0;
    char *line = NULL;
    size_t len = 0;

    if (!file)
        return (-1);
    for (;getline(&line, &len, file) != -1; nb++);
    free(line);
    fclose(file);
    return (nb);
}