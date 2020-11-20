/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:23:21 by celias            #+#    #+#             */
/*   Updated: 2018/07/05 15:45:20 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
