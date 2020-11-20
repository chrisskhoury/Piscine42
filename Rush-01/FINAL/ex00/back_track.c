/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:26:01 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 22:46:24 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		back_track(int **board, int index, int *nbr_sol, int **board_2)
{
	int i;
	int x;
	int y;

	y = index % S_SIZE;
	x = index / S_SIZE;
	if (x == S_SIZE)
	{
		return (call_cp_board(board, board_2, nbr_sol));
	}
	if (board[x][y] != 0)
		return (back_track(board, index + 1, nbr_sol, board_2));
	i = 0;
	while (++i <= S_SIZE)
	{
		board[x][y] = i;
		if (check_all(board, x, y) &&
			back_track(board, index + 1, nbr_sol, board_2))
			return (1);
		else
			board[x][y] = 0;
	}
	return (0);
}

int		call_cp_board(int **board, int **board_2, int *nbr_sol)
{
	*nbr_sol += 1;
	if (*nbr_sol == 1)
	{
		cp_board(board, board_2);
		return (0);
	}
	return (1);
}
