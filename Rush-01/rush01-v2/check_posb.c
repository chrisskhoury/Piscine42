/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_posb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:31:08 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 05:11:05 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	check_row(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[x][i].mode == 0 && i!= y)
			board[x][y].length =
				rm_posb(board[x][y].posb, board[x][y].length, board[x][i].posb[0]);
		i++;
	}
}

void	check_col(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[i][y].mode == 0 && i != x)
			board[x][y].length =
				rm_posb(board[x][y].posb, board[x][y].length, board[i][y].posb[0]);
		i++;
	}
}

void	check_box(t_square **board, int row, int col)
{
	int x;
	int y;
	int box_x;
	int box_y;


	box_x = (row / 3) * 3;
	box_y = (col / 3) * 3;
	x = -1;
	while (++x < 3)
	{
		y = -1;
		while (++y < 3)
			if ((box_x + x != row) && (box_y + y != col))
				if (board[box_x + x][box_y + y].mode == 0)
					board[row][col].length = rm_posb(board[row][col].posb,
							board[row][col].length,
							board[box_x + x][box_y + y].posb[0]);
	}
}
