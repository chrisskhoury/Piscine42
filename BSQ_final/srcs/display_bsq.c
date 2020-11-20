/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:25:11 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 22:06:47 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mhead.h"

void	print_solution(char **grid, t_u32 height, t_u32 width)
{
	t_u32 i;
	t_u32 j;

	i = 1;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	transform_grid(char **lines, t_u32 **grid, char *info, t_u32 ro_la[4])
{
	t_u32 max_val;
	t_u32 i;
	t_u32 j;

	max_val = grid[ro_la[3]][ro_la[2]];
	i = 0;
	while (i < max_val)
	{
		j = 0;
		while (j < max_val)
		{
			lines[ro_la[3] + 1 - i][ro_la[2] - j] = info[2];
			j++;
		}
		i++;
	}
}
