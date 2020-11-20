/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:34:20 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 22:13:44 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	display_board(int **board)
{
	int i;
	int j;

	i = -1;
	while (++i < S_SIZE)
	{
		j = -1;
		while (++j < S_SIZE)
		{
			ft_putchar('0' + board[i][j]);
			if (j != 8)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}
