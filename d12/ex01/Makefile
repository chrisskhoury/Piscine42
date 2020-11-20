# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 12:08:16 by celias            #+#    #+#              #
#    Updated: 2018/07/26 12:23:19 by celias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SOURCE = ft_display_file.c

CC = gcc

CFLAG = -Wextra -Werror -Wall

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SOURCE) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
