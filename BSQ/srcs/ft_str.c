/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:10:07 by celias            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/25 18:46:02 by celias           ###   ########.fr       */
=======
/*   Updated: 2018/07/25 19:29:42 by cel-khou         ###   ########.fr       */
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "types.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

t_u32	ft_atoi(char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str < 32 || *str > 126)
		str++;
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


