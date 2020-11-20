/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:46:01 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 15:02:56 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int		is_numeric_point(char *str)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
	}
	return (1);
}


void	create_board(char **argv, int **board)
{
	int			row;
	int			col;

	row = -1;
	col = -1;
	while (++row < S_SIZE)
	{
		board[row] = (int*)malloc(sizeof(int) * S_SIZE);
		col = -1;
		while (++col < S_SIZE)
		{
			if (argv[row + 1][col] == '.')
				board[row][col] = 0;
			else
				board[row][col] = argv[row + 1][col] - '0';
		}
	}
}
