/*
** EPITECH PROJECT, 2017
** my_puterr.c
** File description:
** For lib
*/

#include <unistd.h>
#include "my.h"

void my_puterr(const char *msg)
{
    write(2, msg, my_strlen(msg));
}