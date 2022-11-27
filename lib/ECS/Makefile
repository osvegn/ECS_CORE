##
## EPITECH PROJECT, 2022
## our_rpg
## File description:
## Makefile
##

SRC		=	source/system.c
			source/world.c

OBJ		=	${SRC:.c=.o}

RM		=	rm -rf

NAME	=	libecs.a

CFLAGS	=	-Wall -Wextra -Wshadow -I include

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	cp include/*.h ../../include

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
