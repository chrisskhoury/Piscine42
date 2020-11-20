/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_given_board.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 22:38:44 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 23:07:07 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int			check_given_board(int **board)
{
	int i;
	int j;

	i = -1;
	while (++i < S_SIZE)
	{
		j = -1;
		while (++j < S_SIZE)
		{
			if (!check_all(board, i, j))
				return (0);
		}
	}
	return (1);
}

void		solve(int **board, int **board_2)
{
	int nbr_sol;

	nbr_sol = 0;
	if (check_given_board(board))
	{
		back_track(board, 0, &nbr_sol, board_2);
		if (nbr_sol == 1)
		{
			display_board(board_2);
			free_memory(board_2);
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
}
