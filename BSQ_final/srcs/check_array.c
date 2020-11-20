/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:27:31 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 22:17:31 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mhead.h"

t_u32	ft_min(t_u32 top, t_u32 top_left, t_u32 left)
{
	t_u32 min;

	min = left;
	if (top_left < min)
		min = top_left;
	else if (top < min)
		min = top;
	return (min);
}

void	check_line2(char line, t_u32 **grid, char *info, t_u32 (*ro_la)[5])
{
	if ((*ro_la)[0] == 0 || (*ro_la)[4] == 0)
	{
		if (line == info[1])
			grid[(*ro_la)[0]][(*ro_la)[4]] = 0;
		else
			grid[(*ro_la)[0]][(*ro_la)[4]] = 1;
	}
	else
	{
		if (line == info[1])
			grid[(*ro_la)[0]][(*ro_la)[4]] = 0;
		else if (line == info[0])
		{
			grid[(*ro_la)[0]][(*ro_la)[4]] = ft_min(grid[(*ro_la)[0] - 1]
					[(*ro_la)[4] - 1], grid[(*ro_la)[0] - 1][(*ro_la)[4]],
					grid[(*ro_la)[0]][(*ro_la)[4] - 1]) + 1;
			if (grid[(*ro_la)[0]][(*ro_la)[4]] > grid[(*ro_la)[3]][(*ro_la)[2]])
			{
				(*ro_la)[3] = (*ro_la)[0];
				(*ro_la)[2] = (*ro_la)[4];
			}
		}
	}
}

t_u32	check_line(char *line, t_u32 **grid, char *info, t_u32 (*ro_la)[5])
{
	t_u32 max;

	max = 0;
	(*ro_la)[4] = -1;
	while (line[++(*ro_la)[4]])
	{
		if (line[(*ro_la)[4]] == info[0] || line[(*ro_la)[4]] == info[1])
		{
			check_line2(line[(*ro_la)[4]], grid, info, ro_la);
		}
		else
			return (0);
	}
	return ((*ro_la)[4]);
}

t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height)
{
	t_u32 width;
	t_u32 ro_la[5];

	ro_la[0] = 0;
	ro_la[1] = 1;
	ro_la[2] = 0;
	ro_la[3] = 0;
	ro_la[4] = 0;
	width = ft_strlen(lines[1]);
	while (ro_la[0] < height)
	{
		grid[ro_la[0]] = (t_u32 *)malloc(sizeof(t_u32) * width);
		if (check_line(lines[ro_la[0] + 1], grid, info, &(ro_la)) != width)
			return (0);
		ro_la[0] = ro_la[0] + 1;
	}
	transform_grid(lines, grid, info, ro_la);
	print_solution(lines, height, width);
	return (width);
}
