/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:10:07 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 19:37:00 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "types.h"
#include <stdio.h>
t_u32	ft_atoi(char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str < 32 || *str > 126)
		str++;
//	if (*str == '-')
//		sign = -1;
//	if (*str == '-' || *str == '+')
//		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (sign * nb);
}

t_u32	ft_strlen(char *str)
{
	t_u32 size;

	size = 0;
	while (*(str + size))
		size++;
	return (size);
}
