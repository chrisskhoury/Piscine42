/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:26:01 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 13:34:15 by hmidoun          ###   ########.fr       */
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
		return (1 + back_track(board, x, y + 1));
	i = 1;
	while (i <= S_SIZE)
	{
		board[x][y] = i;
		if (check_all(board, x, y))
			back_track(board, x, y + 1);
		i++;
	}
	if (i > S_SIZE)
		return (0);
}
