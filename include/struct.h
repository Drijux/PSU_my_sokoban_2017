/*
* @Author: Drijux
* @Date:   2019-09-26 16:24:29
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 17:54:21
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

#define HELP "USAGE: ./my_sokoban path\n\tpath is the path to the map\n"
#define VALID_CHAR  "\n #XOP"
#define SUCCESS     0
#define FAILURE     84

typedef struct game {
	int perso_x;
	int perso_y;
	char **map;
	int end;
	int nb_line;
} game_t;

bool handle_error(game_t *, const char *);
bool loop_game(game_t *);
char handle_dir(char , game_t *);
void print_map(char **, game_t *);

#endif
