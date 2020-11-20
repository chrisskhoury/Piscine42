/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:15:18 by celias            #+#    #+#             */
/*   Updated: 2018/07/05 15:44:56 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_putchars(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	return (0);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0' - 1;
	b = '0';
	c = '1';
	while (++a <= '7')
	{
		while (++b <= '8')
		{
			while (++c <= '9')
			{
				ft_putchars(a, b, c);
				if (a != '7' || b != '8' || c != '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
			c = b + 1;
		}
		b = a;
	}
}
