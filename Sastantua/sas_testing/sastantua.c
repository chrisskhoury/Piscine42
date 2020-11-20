/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:24:56 by celias            #+#    #+#             */
/*   Updated: 2018/07/08 12:59:15 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		get_middle(int size)
{
	int add;
	int middle;

	middle = 0;
	add = 4;
	while (size > 0)
	{
		if ((add + 1) % 3)
		{
			middle += add;
			size--;
		}
		add++;
	}
	return (middle);
}

void	check_display(int size, int row, int col, int dif)
{
	int max_row;
	int door_size;

	max_row = (size * (size + 5)) / 2;
	door_size = (size + (size % 2) - 1) / 2;
	if ((size > 4) && (row == (max_row - door_size)) &&
			(col == get_middle(size) + door_size - 1))
		ft_putchar('$');
	else if (row > (max_row - (2 * door_size) - 1) &&
			(col >= (get_middle(size) - door_size)) &&
			(col <= (get_middle(size) + door_size)))
		ft_putchar('|');
	else if (col < get_middle(size) - dif)
		ft_putchar(' ');
	else if (col == get_middle(size) - dif)
		ft_putchar('/');
	else if ((col > get_middle(size) - dif) &&
			(col < get_middle(size) + dif))
		ft_putchar('*');
	else if (col == get_middle(size) + dif)
		ft_putchar('\\');
}

void	add_jump(int row, int *jump, int *jump_len, int *dif)
{
	if (row == (*jump + *jump_len))
	{
		*jump += *jump_len;
		*jump_len += 1;
		*dif += *jump_len / 2;
	}
}

void	sastantua(int size)
{
	int row;
	int col;
	int dif;
	int jump;
	int jump_len;

	row = 1;
	dif = 1;
	jump = 1;
	jump_len = 3;
	while (row <= (size * (size + 5)) / 2)
	{
		col = 1;
		while (col <= get_middle(size) + dif)
		{
			check_display(size, row, col, dif);
			col++;
		}
		ft_putchar('\n');
		dif++;
		row++;
		add_jump(row, &jump, &jump_len, &dif);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		sastantua(100);
	else if (argc == 2)
		sastantua(argv[1][0] - 48);
	return (0);
}
