/*
* @Author: Drijux
* @Date:   2019-09-26 15:47:53
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 17:52:01
*/

#include <stdlib.h>
#include <ncurses.h>
#include "struct.h"

bool loop_game(game_t *game)
{
    WINDOW *box;
    char c = 0;

    initscr();
    box = newwin(30, 10, 0, 0);
    keypad(box, TRUE);
    nodelay(box, TRUE);
    while ((c = wgetch(box)) != 27 && game->end != 0) {
        clear();
        c = handle_dir(c, game);
        print_map(game->map, game);
        refresh();
    }
    delwin(box);
    endwin();
    return (true);
}