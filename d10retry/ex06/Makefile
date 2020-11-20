# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/19 14:29:30 by celias            #+#    #+#              #
#    Updated: 2018/07/19 14:35:45 by celias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SOURCE = ./calc_func.c ./ft_atoi.c ./handle_func.c ./main.c

CC = gcc

CFLAG = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SOURCE) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
