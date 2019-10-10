##
## @Author: Drijux
## @Date:   2019-09-26 15:49:04
## @Last Modified by:   Drijux
##

NAME	=	my_sokoban

SRC		=	src/main.c\
			src/handle_error.c\
			src/loop_game.c\
			src/handle_perso.c\
			src/print_function.c

CFLAGS	+=	-I./include -Wall -Wextra -lncurses

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./lib/my -lmy
clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all
	make fclean clean -C lib/my

.PHONY: all clean fclean re
