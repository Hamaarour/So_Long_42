# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:02:58 by hamaarou          #+#    #+#              #
#    Updated: 2023/01/05 13:34:38 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror
FRAMWORK= -lmlx -framework OpenGL -framework AppKit
PATH=-I /usr/local/include

SRC= 	Libft/libft_utils.c Libft/ft_split.c Libft/ft_itoa.c\
		ft_printf/ft_printf_utils.c ft_printf/ft_printf.c \
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		map_handl/utils.c map_handl/check_map.c map_handl/render_map.c map_handl/check_two_map.c\
		move_player/move_player.c  \
		move_player/msg.c \
		map_handl/bonus.c map_handl/check_path.c \
		main.c


OBJ= $(SRC:.c=.o)

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(PATH) $(SRC) $(FRAMWORK) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all
