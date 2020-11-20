/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 01:10:55 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 01:44:58 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		verify_box(t_square **board, int row, int col)
{
	int x;
	int y;
	int box_x;
	int box_y;


	if (board[row][col].length == 1)
	{
		box_x = (row / 3) * 3;
		box_y = (col / 3) * 3;
		x = -1;
		while (++x < 3)
		{
			y = -1;
			while (++y < 3)
				if (((box_x + x != row) && (box_y + y != col))
					&& (board[box_x + x][box_y + y].length == 1)
					&& (board[row][col].posb[0] ==
					board[box_x + x][box_y + y].posb[0]))
							return (0);

		}
	}
	return (1);
}
