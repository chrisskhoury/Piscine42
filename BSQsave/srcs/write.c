/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:58:06 by cel-khou          #+#    #+#             */
/*   Updated: 2018/07/25 19:56:34 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "types.h"
#include "ft_str.h"

t_u32 ft_min(t_u32 top, t_u32 top_left, t_u32 left)
{
	t_u32 min;

	min = left;
	if (top_left < min)
		min = top_left;
	else if (top < min)
		min = top;
	return (min);
}

void	print_solution(char **grid, t_u32 height, t_u32 width)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			printf("%c", grid[i][j]);
		printf("\n");
	}

}

void	print_table(t_u32 **grid, t_u32 height, t_u32 width)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			printf("%d", grid[i][j]);
		printf("\n");
	}

}

t_u32	check_line(char *line, t_u32 **grid, char *info, t_u32 (*ro_la)[4])
{
	t_u32 col;
	t_u32 max;

	max = 0;
	col = -1;
	while (line[++col])
	{
		if (line[col] == info[0] || line[col] == info[1])
		{
			if ((*ro_la)[0] == 0 || col == 0)
			{
				if (line[col] == info[1])
					grid[(*ro_la)[0]][col] = 0;
				else
					grid[(*ro_la)[0]][col] = 1;
			}
			else
			{
				if (line[col] == info[1])
					grid[(*ro_la)[0]][col] = 0;
				else if (line[col] == info[0])
				{
					grid[(*ro_la)[0]][col] = ft_min(grid[(*ro_la)[0] - 1][col - 1],
							grid[(*ro_la)[0] - 1][col],
							grid[(*ro_la)[0]][col - 1]) + 1;
					if (grid[(*ro_la)[0]][col] > grid[(*ro_la)[3]][(*ro_la)[2]])
					{	
//						max++; 
						(*ro_la)[3] = (*ro_la)[0];
						(*ro_la)[2] = col;
					}
				}
			}
		}
		else
			return (0);
	}
	return (col);
}

void	transform_grid(char **lines, t_u32 **grid, char *info ,t_u32 ro_la[4])
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

t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height)
{
	t_u32 width;
	t_u32 ro_la[4];

//	if (!(ro_la = (t_u32*)malloc(sizeof(t_u32) * 4)))
//		return (0);
	/* note that 0 > row | 3 -> row of largest | 2 > column of largest*/
	ro_la[0] = 0;
	ro_la[1] = 1;
	ro_la[2] = 0;
	ro_la[3] = 0;
	width = ft_strlen(lines[1]);
	while (ro_la[0] < height)
	{
		grid[ro_la[0]] = (t_u32 *)malloc(sizeof(t_u32)*width);
		if (check_line(lines[ro_la[0] + 1], grid, info, &(ro_la)) != width)
			return(0);
		ro_la[0] = ro_la[0] + 1;
	}
	transform_grid(lines, grid, info, ro_la);
	print_solution(lines, height, width);
	return(width);
}
