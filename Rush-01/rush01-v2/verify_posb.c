/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_posb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:31:08 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 01:45:29 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		check_row(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[x][i].length == 1 && i!= y)
		{
			if (board[x][y].posb[0] = board[x][i].posb[0])
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_col(t_square **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (board[i][y].length == 1 && i != x)
		{
			if (board[x][y].posb[0] = board[i][y].posb[0])
				return (0);
		}
		i++;
	}
	return (1);
}

