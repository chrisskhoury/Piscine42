# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 18:51:18 by celias            #+#    #+#              #
#    Updated: 2018/07/22 23:18:19 by gguichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SOURCE = srcs/check_rush_generic.c \
		 srcs/check_rushes.c \
		 srcs/read_stdin.c \
		 srcs/ft_functions.c \
		 srcs/main.c

HEADERS = includes/

CC = gcc

CFLAG = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -I$(HEADERS) $(SOURCE) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
