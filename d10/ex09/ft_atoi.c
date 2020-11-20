/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 00:58:03 by celias            #+#    #+#             */
/*   Updated: 2018/07/19 13:04:45 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str < 32 || *str > 126)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (sign * nb);
}

int		ft_check_args(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (0);
	}
	return (1);
}
