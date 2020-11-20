/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:04:45 by celias            #+#    #+#             */
/*   Updated: 2018/07/11 01:48:48 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_nb(unsigned int nbr, char *base, int base_size)
{
	if (nbr < base_size)
		ft_putchar(base[nbr])
	else
	{
		ft_print_nb(nbr / base_size, base, base_size);
		ft_putchar(base[nbr % base_size]);
	}
}

int		ft_check_base(char *base, int size)
{
	int		i;
	char	search;

	if (size < 2)
		return (0);
	size = 0;
	while (base[size] != '\0')
	{
		if (base[size] == '-' || base[size] == '+'
				|| base[size] < 33 || base[size] > 126)
			return (0);
		i = size;
		search = base[size];
		while (base[++i] != '\0')
		{
			if (search == base[i])
				return (0);
		}
		size++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_size;
	unsigned int	number;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	if (ft_check_base(base, base_size))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			number = -nbr;
		}
		else
			number = nbr;
		ft_print_nb(number, base, base_size);
	}
}

int main()
{
	ft_putnbr_base(131744, "0123456789ABCDEF") ;
}
