/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 11:30:23 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 22:38:25 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		check_argv(int argc, char **argv)
{
	int i;

	if (ft_sqrt(S_SIZE) == 0)
		return (0);
	if (argc == S_SIZE + 1)
	{
		i = 0;
		while (++i < S_SIZE + 1)
			if ((ft_strlen(argv[i]) != S_SIZE)
					|| !is_numeric_point(argv[i]))
				return (0);
		return (1);
	}
	return (0);
}

int		check_row(int **board, int x, int y)
{
	int i;

	i = 0;
	while (i < S_SIZE)
	{
		if (board[x][i] != 0 && i != y)
		{
			if (board[x][y] == board[x][i])
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_col(int **board, int x, int y)
{
	int i;

	i = 0;
	while (i < S_SIZE)
	{
		if (board[i][y] != 0 && i != x)
		{
			if (board[x][y] == board[i][y])
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_box(int **board, int row, int col)
{
	int x;
	int y;
	int box_x;
	int box_y;
	int sqrt_size;

	sqrt_size = ft_sqrt(S_SIZE);
	box_x = (row / sqrt_size) * sqrt_size;
	box_y = (col / sqrt_size) * sqrt_size;
	x = -1;
	while (++x < sqrt_size)
	{
		y = -1;
		while (++y < sqrt_size)
		{
			if ((box_x + x != row) && (box_y + y != col) &&
					(board[box_x + x][box_y + y] != 0))
			{
				if (board[box_x + x][box_y + y] == board[row][col])
					return (0);
			}
		}
	}
	return (1);
}

int		check_all(int **board, int row, int col)
{
	if (check_row(board, row, col)
			&& check_col(board, row, col)
			&& check_box(board, row, col))
		return (1);
	return (0);
}
