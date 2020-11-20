/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:46:01 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 22:32:26 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		is_numeric_point(char *str)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if ((str[i] < '0' || str[i] > '9')
				&& str[i] != '.')
		{
			return (0);
		}
	}
	return (1);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i < nb / i)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	return (0);
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

void	cp_board(int **board, int **board_2)
{
	int			row;
	int			col;

	row = -1;
	col = -1;
	while (++row < S_SIZE)
	{
		board_2[row] = (int*)malloc(sizeof(int) * S_SIZE);
		col = -1;
		while (++col < S_SIZE)
		{
			board_2[row][col] = board[row][col];
		}
	}
}

void	free_memory(int **board)
{
	int i;

	i = 0;
	while (i < S_SIZE)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
