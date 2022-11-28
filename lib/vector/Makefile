##
## EPITECH PROJECT, 2022
## our_rpg
## File description:
## Makefile
##

SRC		=	source/constructor.c \
			source/destructor.c \

OBJ		=	${SRC:.c=.o}

RM		=	rm -rf

NAME	=	libvector.a

CFLAGS	=	-Wall -Wextra -Wshadow -I include -g

${NAME}: all

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

debug: CFLAGS += -g
debug: re
