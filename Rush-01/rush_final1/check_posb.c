/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_posb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:31:08 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 00:26:17 by hmidoun          ###   ########.fr       */
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

