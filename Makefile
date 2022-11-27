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

ecs:
	make -C lib/ECS
	make -C lib/ECS clean

ecs_clean:
	make -C lib/ECS clean

ecs_fclean:
	make -C lib/ECS fclean

linked_list_clean:
	make -C lib/linked_list clean

linked_list_fclean:
	make -C lib/linked_list fclean

all: ${OBJ}
	${CC} -o ${NAME} ${OBJ} ${CFLAGS}

clean: ecs_clean linked_list_clean
	${RM} ${OBJ}

fclean: clean ecs_fclean linked_list_fclean
	${RM} ${NAME}
	${RM} lib/include/*
	${RM} lib/archive/*

re: fclean ${NAME}

debug: CFLAGS += -g
debug: re