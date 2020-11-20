/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_posb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:31:08 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/14 23:46:19 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	check_col(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[i][x].mode == 0 && i != y)
			board[y][x].length =
			rm_posb(board[y][x].posb, board[y][x].length, board[i][x].posb[0]);
		i++;
	}
}

void	check_row(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[y][i].mode == 0 && i != x)
			board[y][x].length =
			rm_posb(board[y][x].posb, board[y][x].length, board[y][i].posb[0]);
		i++;
	}
}

