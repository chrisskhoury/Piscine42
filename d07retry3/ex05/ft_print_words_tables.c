/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:44:54 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 01:36:18 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		**ft_split_whitespaces(char *str);

void		ft_putchar(char c)
{
	write (1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void		ft_print_words_tables(char **tab)
{
	while (*tab != 0)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

int		main(int argc, char **argv)
{
	char **s;
	s = ft_split_whitespaces(argv[1]);
	ft_print_words_tables(s);
}
