/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:05:01 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 23:07:30 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int		main(int argc, char **argv)
{
	int **board;
	int	**board_2;

	if (check_argv(argc, argv))
	{
		board = (int**)malloc(sizeof(int*) * S_SIZE);
		board_2 = (int**)malloc(sizeof(int*) * S_SIZE);
		create_board(argv, board);
		solve(board, board_2);
		free_memory(board);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
