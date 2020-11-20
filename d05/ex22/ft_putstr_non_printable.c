/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:37:26 by celias            #+#    #+#             */
/*   Updated: 2018/07/10 17:55:53 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_nb(int nbr, char *base, int base_size)
{
	if (nbr > 0)
	{
		if (nbr < 16)
			ft_putchar('0');
		ft_print_nb(nbr / base_size, base, base_size);
		ft_putchar(base[nbr % base_size]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str > 126)
		{
			ft_putchar('\\');
			ft_print_nb(*str, "0123456789abcdef", 16);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
