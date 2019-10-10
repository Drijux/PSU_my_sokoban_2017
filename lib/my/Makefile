##
## EPITECH PROJECT, 2017
## For my lib
## File description:
## Makefile (lib)
##

CC	=		gcc

AR	=		ar rc

CFLAGS	+=	-Wall -Wextra

NAME	=	libmy.a

SRCS	=	my_strcpy.c\
			my_strlen.c\
			my_strdup.c\
			my_putstr.c\
			my_file_linelen.c\
			my_puterr.c\
			my_strcmp.c


OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		cp my.h ../../include
		$(AR) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
fclean:	clean
		rm -f $(NAME)
		rm -f *.a

re:	fclean all

.PHONY: all clean fclean re $(NAME)
