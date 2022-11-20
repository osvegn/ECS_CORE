##
## EPITECH PROJECT, 2022
## my_my_hunter
## File description:
## Makefile
##

SRC		=	create_linked_list.c \
			destroy_linked_list.c \
			at_linked_list.c \
			front_linked_list.c \
			back_linked_list.c \
			empty_linked_list.c \
			size_linked_list.c \
			insert_linked_list.c \
			push_back_linked_list.c \
			remove_linked_list.c \

OBJ		=	${SRC:.c=.o}

RM		=	rm -rf

NAME	=	liblinked_list.a

CFLAGS	=	-Wall -Wextra -Wshadow -I include

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	cp include/linked_list.h ../../include

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
