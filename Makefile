# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:02:58 by hamaarou          #+#    #+#              #
#    Updated: 2022/12/22 15:00:19 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
FRAMWORK=-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
PATH=-I /usr/local/include 

SRC= 	Libft/libft_utils.c Libft/ft_split.c \
		ft_printf/ft_printf_utils.c ft_printf/ft_printf.c \
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		map_handl/utils.c map_handl/check_map.c map_handl/render_map.c


OBJ=	Libft/libft_utils.o Libft/ft_split.o \
		ft_printf/ft_printf_utils.o ft_printf/ft_printf.o \
		get_next_line/get_next_line_utils.o get_next_line/get_next_line.o \
		map_handl/utils.o map_handl/check_map.o map_handl/render_map.o

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:%.c
	$(CC)  -c $? -o $@

# compile: all
# 	$(CC) $(CFLAGS) $(PATH) main.c $(NAME) $(FRAMWORK) 
clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all