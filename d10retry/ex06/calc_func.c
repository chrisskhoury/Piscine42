/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 23:48:50 by celias            #+#    #+#             */
/*   Updated: 2018/07/19 00:56:52 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_sum(int a, int b)
{
	ft_putnbr(a + b);
}

void		ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void		ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void		ft_div(int a, int b)
{
	if (!b)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void		ft_mod(int a, int b)
{
	if (!b)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
