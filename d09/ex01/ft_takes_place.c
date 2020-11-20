/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:39:10 by celias            #+#    #+#             */
/*   Updated: 2018/07/12 20:08:40 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar_int(int a)
{
	unsigned int	divisor;
	unsigned int	b;
	char			c;

	divisor = 1;
	b = a;
	while (b > 9)
	{
		b /= 10;
		divisor *= 10;
	}
	while (divisor >= 1)
	{
		c = (a / divisor) + 48;
		write(1, &c, 1);
		a %= divisor;
		divisor /= 10;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	unb;
	char			c;

	c = '-';
	if (nb < 0)
	{
		write(1, &c, 1);
		unb = -1 * nb;
	}
	else
	{
		unb = nb;
	}
	ft_putchar_int(unb);
}

int		get_hour(int hour, char *am_pm)
{
	if (hour >= 12)
	{
		*am_pm = 'P';
		if (hour == 12)
			return (hour);
	}
	else
	{
		*am_pm = 'A';
		if (hour == 0)
			return (12);
	}
	return (hour % 12);
}

void	ft_takes_place(int hour)
{
	char am_pm1;
	char am_pm2;

	ft_putstr("THE FOLLOWING TAKES PLACE BETWEEN ");
	ft_putnbr(get_hour(hour % 24, &am_pm1));
	ft_putstr(".00 ");
	write(1, &am_pm1, 1);
	ft_putstr(".M. AND ");
	ft_putnbr(get_hour((hour + 1) % 24, &am_pm2));
	ft_putstr(".00 ");
	write(1, &am_pm2, 1);
	ft_putstr(".M.\n");
}
