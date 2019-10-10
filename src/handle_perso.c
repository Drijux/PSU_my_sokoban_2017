/*
* @Author: Drijux
* @Date:   2019-09-26 15:49:04
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 16:09:45
*/


#include <ncurses.h>
#include "struct.h"

static bool valid_move(game_t *game, int x, int y)
{
    char save = 0;

    if (game->map[game->perso_y + y][game->perso_x + x] != 'X')
        return (true);
    if (game->map[game->perso_y + y + y][game->perso_x + x + x] == ' '
        || game->map[game->perso_y + y + y][game->perso_x + x + x] == 'O') {
        save = game->map[game->perso_y + y + y][game->perso_x + x + x];
        if (save == 'O') {
            save = ' ';
            game->end--;
        }
        game->map[game->perso_y + y + y][game->perso_x + x + x]
        = game->map[game->perso_y + y][game->perso_x + x];
        game->map[game->perso_y + y][game->perso_x + x] = save;
        return (true);
    }
    return (false);
}

static void move_perso(game_t *game, int x, int y)
{
    char save = 0;

    if ((game->map[game->perso_y + y][game->perso_x + x] == ' '
        || game->map[game->perso_y + y][game->perso_x + x] == 'X')
        && valid_move(game, x, y)) {
        save = game->map[game->perso_y + y][game->perso_x + x];
        game->map[game->perso_y + y][game->perso_x + x]
        = game->map[game->perso_y][game->perso_x];
        game->map[game->perso_y][game->perso_x] = save;
        game->perso_x += x;
        game->perso_y += y;
    }
}

char handle_dir(char c, game_t *game)
{
    switch(c) {
        case 3: // KEY_DOWN
            move_perso(game, 0, -1);
            break;
        case 2: // KEY_UP
            move_perso(game, 0, 1);
            break;
        case 4: // KEY_LEFT
            move_perso(game, -1, 0);
            break;
        case 5: // KEY_RIGHT
            move_perso(game, 1, 0);
            break;
    }
    return (0);
}