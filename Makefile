##
## EPITECH PROJECT, 2022
## my_my_hunter
## File description:
## Makefile
##

SRC		=	sources/main.c \
			sources/my_hunter.c \
			sources/Component/vector.c \
			sources/Resource/render_window.c \
			sources/System/display_window.c \
			sources/World/world.c \
			sources/System/system.c

OBJ		=	${SRC:.c=.o}

NAME 	=	my_hunter

CFLAGS	=	-Wall -Wextra -Wshadow -lcsfml-graphics -iquote ./include -L lib/linked_list -llinked_list

CC		=	gcc

RM		=	rm -rf

${NAME}: linked_list all

linked_list:
	make -C lib/linked_list
	make -C lib/linked_list clean

lib_clean:
	make -C lib/linked_list clean

lib_fclean:
	make -C lib/linked_list fclean

all: ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${CFLAGS}

clean: lib_clean
	${RM} ${OBJ}

fclean: clean lib_fclean
	${RM} ${NAME}

re: fclean ${NAME}

debug: CFLAGS += -g
debug: re