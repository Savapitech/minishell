##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to build project
##

NAME	=	libmy.a

SRCS = my_compute_power_rec.c \
       my_compute_square_root.c \
	my_put_float.c \
	my_put_float_upper.c \
       my_put_address.c \
       my_isneg.c \
       my_put_nbr.c \
       my_put_unsigned_nbr.c \
       my_put_hexa.c \
       my_put_hexa_upper.c \
       my_put_octal.c \
       my_putchar.c \
       my_getnbr.c \
       my_putstr.c \
       my_puterr.c \
       my_revstr.c \
       my_show_word_array.c \
       my_str_to_word_array.c \
       my_strcat.c \
       my_strcmp.c \
       my_strncmp.c \
       my_strshift.c \
       my_strcpy.c \
       my_strdup.c \
       my_strlen.c \
       my_strncat.c \
       my_strncpy.c \
       my_swap.c \
	my_printf.c \
	my_format.c \
	my_strpop.c \
       my_str_isalpha.c \
       my_str_isdigit.c \
       my_char_isalpha.c \
       my_char_isnum.c \
       my_freestr.c \
       my_str_isalphanum.c


OBJS	=	$(SRCS:.c=.o)

CC = gcc

CFLAGS = -c -Iinclude -Wextra -Wall

all:  $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) *.o
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
