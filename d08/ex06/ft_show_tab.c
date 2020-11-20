/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:48:58 by celias            #+#    #+#             */
/*   Updated: 2018/07/17 20:13:19 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int a)
{
	unsigned int divisor;
	unsigned int b;

	divisor = 1;
	b = a;
	while (b > 9)
	{
		b /= 10;
		divisor *= 10;
	}
	while (divisor >= 1)
	{
		ft_putchar((a / divisor) + 48);
		a %= divisor;
		divisor /= 10;
	}
}

void	ft_print_words_tables(char **tab)
{
	while (*tab != 0)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	while (par->str)
	{
		ft_putstr(par->copy);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		ft_print_words_tables(par->tab);
		par++;
	}
}
