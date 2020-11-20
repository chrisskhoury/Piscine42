# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/22 20:56:12 by celias            #+#    #+#              #
#    Updated: 2018/07/22 23:11:27 by celias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRC = ./srcs/ft_eval_exp.c ./srcs/ft_functions.c ./srcs/main.c
HEADER = ./includes/

all: $(NAME)

$(NAME):
		    gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) -I $(HEADER)

clean :
			rm -f *.o

fclean : clean
			rm -f $(NAME)
			
re: clean all
