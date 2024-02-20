##
## EPITECH PROJECT, 2024
## B-PSU-200-REN-2-1-minishell1-savinien.petitjean
## File description:
## Makefile
##

NAME	=	mysh

SRCS = src/main.c \
       src/utils/get_path.c \
	   src/utils/parse_args.c \
	   src/exec_prog.c \
	   src/utils/parse_buffer.c

CC = gcc

CFLAGS = -Iincludes -Llib/my -lmy -Wextra -Wall -Werror

all:  $(NAME)

$(NAME):
	cd lib/my && make -j16
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean:	clean
	cd lib/my && make fclean
	$(RM) $(NAME)
	$(RM) *.gc*
	$(RM) unit_tests

re:	fclean all

asan: fclean
	cd lib/my && make
	$(CC) $(SRCS) -o $(NAME) -lasan -g3 $(CFLAGS)
