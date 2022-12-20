# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:02:58 by hamaarou          #+#    #+#              #
#    Updated: 2022/12/20 14:44:06 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC= 	 ./Libft/ft_split.c ./Libft/ft_strncmp.c ./Libft/ft_calloc.c ./Libft/ft_strjoin_split.c ./Libft/ft_substr.c \
		./fr_printf/ft_printf_utils.c ./fr_printf/ft_printf.c \


OBJ=	./Libft/ft_split.o ./Libft/ft_strncmp.o ./Libft/ft_calloc.o ./Libft/ft_strjoin_split.o ./Libft/ft_substr.o \
		./fr_printf/ft_printf_utils.o ./fr_printf/ft_printf.o \

all:$(NAME)

.PHONY= all clean fclean re

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all