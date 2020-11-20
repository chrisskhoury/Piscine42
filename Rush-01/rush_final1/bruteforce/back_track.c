/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:26:01 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 14:37:11 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		back_track(int **board, int x, int y)
{
	int i;

	if (y == S_SIZE)
	{
		y = 0;
		x++;
	}
	if (x == S_SIZE)
		return (1);
	if (board[x][y] != 0)
		return ( back_track(board, x, y + 1));
	i = 1;
	while (i <= S_SIZE)
	{
		board[x][y] = i;
		if (check_all(board, x, y))
		{
			if(back_track(board, x, y + 1))
				return (1);
			else
				board[x][y] = 0;
		}
		else
			board[x][y] = 0;
		
		i++;
		
	}

	return (0);
}
/*
int       ft_solve_sudoku(int **numbers, int value)
{
	int i;
	int x;
	int y;

	i = 1;
	x = value / V_SIZE;
	y = value % V_SIZE;
	if (value == V_SIZE * V_SIZE)
		return (1);
	if (numbers[x][y] != 0)
		return (ft_solve_sudoku(numbers, value + 1));
	while (i < V_SIZE + 1)
	{
		if (ft_check_row_col(numbers, x, y, i) && ft_check_cube(numbers, x, y, i))
		{
			numbers[x][y] = i;
			if (ft_solve_sudoku(numbers, value + 1))
				return (1);
			else
				numbers[x][y] = 0;
		}
		i++;
	}
	return (0);
}
*/
