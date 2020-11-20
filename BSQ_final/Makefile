# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 19:58:40 by celias            #+#    #+#              #
#    Updated: 2018/07/25 21:34:01 by celias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SOURCE = ./srcs/main.c \
		 ./srcs/check_array.c \
		 ./srcs/ft_str.c \
		 ./srcs/check_bsq.c \
		 ./srcs/display_bsq.c \
		 ./srcs/read_file.c

HEADERS = ./includes

CC = gcc

CFLAG = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
		$(CC) $(CFLAG) -I$(HEADERS) $(SOURCE) -o $(NAME)

clean:

fclean: clean
		rm -f $(NAME)

re: fclean all
