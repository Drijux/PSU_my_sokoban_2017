/*
* @Author: Drijux
* @Date:   2019-09-26 15:48:53
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 16:19:49
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "struct.h"
#include "my.h"

static bool check_char_line(const char carac, int x, int y, game_t *game)
{
    if (carac == 'O')
        game->end++;
    for (int j = 0; j < my_strlen(VALID_CHAR); j++) {
        if (carac == 'P') {
            game->perso_x = x;
            game->perso_y = y;
        }
        if (carac == VALID_CHAR[j])
            return (true);
    }
    my_puterr("ERROR: INVALID MAP");
    return (false);
}

static bool check_line(const char *src, int y, game_t *game)
{
    for (int i = 0; i < my_strlen(src); i++) {
        if (!check_char_line(src[i], i, y, game))
            return (false);
    }
    return (true);
}

static bool register_map(game_t *game, FILE *file, int nb_line)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if ((game->map = malloc(sizeof(char*) * (nb_line + 1))) == NULL)
        return (false);
    for (int i = 0; (read = getline(&line, &len, file)) != -1; i++) {
        if (!check_line(line, i, game) || (game->map[i] = my_strdup(line)) == NULL)
            return (false);
    }
    free(line);
    game->map[nb_line] = NULL;
    return (true);
}

bool handle_error(game_t *game, const char *pathname)
{
    FILE *file;
    int nb_line = my_file_linelen(pathname);

    file = fopen(pathname, "r");
    game->end = 0;
    game->nb_line = nb_line;
    if (!file || nb_line == -1) {
        perror("fopen failed");
        return (false);
    }
    if (!register_map(game, file, nb_line))
        return (false);
    fclose(file);
    return (true);
}