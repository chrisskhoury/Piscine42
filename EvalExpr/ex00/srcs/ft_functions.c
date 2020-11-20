/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 01:03:56 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 23:11:07 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/func.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char **str)
{
	int number;
	int negative;

	number = 0;
	negative = 1;
	if (**str == '-')
		negative = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		number *= 10;
		number += ((**str) - 48);
		(*str)++;
	}
	return (number * negative);
}

int		divider(int nb)
{
	int div;

	div = 1;
	while (nb >= 10)
	{
		nb /= 10;
		div *= 10;
	}
	return (div);
}

void	ft_putnbr(int nb)
{
	int div;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	div = divider(nb);
	while (div > 0)
	{
		ft_putchar(nb / div + 48);
		nb %= div;
		div /= 10;
	}
}
