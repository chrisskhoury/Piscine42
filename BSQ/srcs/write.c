/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:58:06 by cel-khou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/25 19:48:23 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
=======
/*   Updated: 2018/07/24 17:29:47 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
#include <stdlib.h>
#include "lists.h"
#include "types.h"
#include "ft_str.h"
<<<<<<< HEAD

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
=======

t_u32 ft_min(t_u32 top, t_u32 top_left, t_u32 left)
{
	t_u32 min;

	min = left;
	if (top_left < min)
		min = top_left;
	else if (left < min)
		min = left;
	return (min);
}

t_u32 check_line(char *line, t_u32 **grid, char *info, t_u32 row, t_u32 large)
{
	int col;

				printf("asdfl");
	col = 0;
	while (line[col] != '\0')
	{
		printf("\ninfo %c, %c, %c", line[0], line[1] , line[2] );
		if ((line[col] == info[0] || line[col] == info[1]))
		{
			if (line[col] == info[1])
				grid[row][col] = 0;
			else if (col == 0)
				grid[row][col] = 1;
			else if (col > 0)
			{
				grid[row][col] = ft_min(grid[row - 1][col], grid[row - 1][col - 1], grid[row][col - 1]) + 1;
				large = ((grid[row][col] > large) ? grid[row][col] : large);
			}
			else
				printf("FUCKIT________");
		}
		else 
			return (0);
		col++;
	}
	return (col);
}
void    print_grid(t_u32 **grid, t_u32 height, t_u32 width);
t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height)
{
	printf("--------------");
	t_u32 row;
	t_u32 width;
	t_u32 large;

	row = 0;
	large = 0;
	width = ft_strlen(lines[0]);
	while (row < height)
	{
		grid[row] = (t_u32 *)malloc(sizeof(t_u32)*width);
		if (check_line(lines[row + 1], grid, info, row, large) != width)
			return(0);
		row++;
	}
	print_grid(grid, height, width);
	return(width);
}

/*
t_u32	get_width(t_list *line)
{
	t_u32 width;

	width = 0;
	t_list current = line;
	while(current != NULL)
	{
		width++;
		current = current -> next;
	}
	return (width);
}

t_u32	check_fline(t_list **fline, int **grid, char *info, t_u32 height)
{
	int col;

	col = 0;
	while(fline != NULL)
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
	{
		if (line[col] == info[0] || line[col] == info[1])
		{
<<<<<<< HEAD
			if ((*ro_la)[0] == 0 || col == 0)
			{
				if (line[col] == info[1])
					grid[(*ro_la)[0]][col] = 0;
				else
					grid[(*ro_la)[0]][col] = 1;
			}
=======
			if (fline -> data == info[1])
				grid[0][col] = 0;
			else if (fline -> data == info[0])
				grid[0][col] = 1;
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
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
<<<<<<< HEAD
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
=======
		col++;
	}
}*/
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
