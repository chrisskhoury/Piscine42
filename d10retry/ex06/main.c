/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 23:17:05 by celias            #+#    #+#             */
/*   Updated: 2018/07/19 12:59:34 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		a;
	int		b;
	int		i;
	char	*signs;
	void	(*calc_exp[5])(int a, int b);

	calc_exp[0] = ft_sum;
	calc_exp[1] = ft_sub;
	calc_exp[2] = ft_mul;
	calc_exp[3] = ft_div;
	calc_exp[4] = ft_mod;
	if (!ft_check_args(argc, argv))
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	signs = "+-*/%";
	i = -1;
	while (signs[++i])
		if (signs[i] == argv[2][0])
		{
			calc_exp[i](a, b);
			ft_putchar('\n');
			return (0);
		}
	ft_putstr("0\n");
}
