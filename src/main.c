/*
* @Author: Drijux
* @Date:   2019-09-26 15:42:46
* @Last Modified by:   Drijux
* @Last Modified time: 2019-09-26 17:52:35
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "my.h"

static void free_map(game_t *game)
{
    for (int i = 0; game->map[i]; i++)
        free(game->map[i]);
    free(game->map);
}

static int print_usage(void)
{
    my_putstr(HELP);
    return (SUCCESS);
}

int	main(int ac, char **av)
{
	game_t game;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        return(print_usage());
    }
	if (ac != 2 || !handle_error(&game, av[1])) {
		return (FAILURE);
    }
    if (!loop_game(&game)) {
        return (FAILURE);
    }
	free_map(&game);
	return (SUCCESS);
}
