/*
* @Author: Drijux
* @Date:   2019-09-26 16:08:55
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 17:53:51
*/

#include <ncurses.h>
#include "struct.h"
#include "my.h"

void print_map(char **map, game_t *game)
{
    for (int i = 0; map[i]; i++)
        mvprintw((LINES / 2) - (game->nb_line - i) , COLS / 2, "%s", map[i]);
}