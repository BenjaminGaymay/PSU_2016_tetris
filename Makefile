##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
##
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
##
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Sun Mar 19 19:15:42 2017 Benjamin GAYMAY
##

CC	=	gcc

NAME	=	tetris

SRC	=	./src/read.c \
		./src/main.c \
		./src/pimp.c \
		./src/pimpv2.c \
		./src/fall.c \
		./src/error.c \
		./src/flag.c \
		./src/score.c \
		./src/error_gest.c \
		./src/moves.c \
		./src/debug.c \
		./src/debug_3.c \
		./src/ncurse.c \
		./src/option.c \
		./src/flag_2.c \
		./src/tetris.c \
		./src/colors.c \
		./src/delete.c \
		./src/tetris_2.c \
		./src/debug_2.c \
		./src/print_map.c \
		./src/tetriminos.c \
		./src/tetriminos_2.c \
		./src/put_tetriminos.c \
		./src/count_tetriminos.c \
		./src/columns_and_rows.c \
		./basics/get_next_line.c \
		./basics/my_putstr.c \
		./basics/my_strstr.c \
		./basics/my_putchar.c \
		./basics/my_getnbr.c \
		./basics/my_strcmp.c \
		./basics/use_array.c \
		./basics/my_showtab.c \
		./basics/my_strncmp.c \
		./basics/my_str_isnum.c \
		./basics/my_str_isnum2.c \
		./basics/chained_list.c \
		./basics/my_end_strcmp.c \
		./basics/my_malloc_strcat.c \
		./my_printf/flag.c \
                ./my_printf/hexa.c \
                ./my_printf/octal_bin.c \
                ./my_printf/my_printf.c \
                ./my_printf/my_putstr_printf.c \
                ./my_printf/my_strlen_printf.c \
		./my_printf/my_put_nbr_printf.c \
		./my_printf/my_putchar_printf.c \
                ./my_printf/my_put_nbr_unsigned.c \
                ./my_fprintf/fflag.c \
                ./my_fprintf/fhexa.c \
                ./my_fprintf/my_fprintf.c \
                ./my_fprintf/foctal_bin.c \
                ./my_fprintf/my_putstr_fprintf.c \
                ./my_fprintf/my_strlen_fprintf.c \
		./my_fprintf/my_putchar_fprintf.c \
                ./my_fprintf/my_put_nbr_fprintf.c \
                ./my_fprintf/my_put_nbr_funsigned.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS +=	-I./include -Wall -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
