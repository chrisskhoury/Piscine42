/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 04:24:49 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 11:34:01 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		back_track(t_square **board, int x, int y, int index, int single_count)
{
	int i;

	if (board[x][y].mode == 0)
	{
		if (y == 8)
			back_track(board, x + 1, 0);
		else
			back_track(board, x, y + 1);
	}
	else
	{
		i = 0;
		while(i < board[x][y].length )
		{
			
		}
	}
}
