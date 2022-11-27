##
## EPITECH PROJECT, 2022
## our_rpg
## File description:
## Makefile
##

SRC		=	source/world.c

OBJ		=	${SRC:.c=.o}

RM		=	rm -rf

NAME	=	libecs.a

CFLAGS	=	-Wall -Wextra -Wshadow -I include -L ../linked_list/ -llinked_list -I ../include

${NAME}: linked_list all

linked_list:
	make -C ../linked_list

all: ${OBJ}
	ar rc ${NAME} ${OBJ}
	cp include/*.h ../include
	cp ${NAME} ../archive
	make clean

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
