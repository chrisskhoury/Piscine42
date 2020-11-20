/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:06:41 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 01:09:32 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

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
