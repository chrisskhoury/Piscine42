/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 23:56:07 by celias            #+#    #+#             */
/*   Updated: 2018/07/19 00:58:30 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar_int(int a)
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

void	ft_putnbr(int nb)
{
	unsigned int unb;

	if (nb < 0)
	{
		ft_putchar('-');
		unb = -1 * nb;
	}
	else
	{
		unb = nb;
	}
	ft_putchar_int(unb);
}

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*(str + size) != '\0')
		size++;
	return (size);
}
