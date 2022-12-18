# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:02:58 by hamaarou          #+#    #+#              #
#    Updated: 2022/12/17 13:18:34 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
MINILIBX= -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
SRC =

OBJ =

all:$(NAME)

.PHONY= all fclean clean re

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) -c $(src)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all