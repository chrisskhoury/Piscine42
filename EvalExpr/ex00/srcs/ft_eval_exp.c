/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 03:12:31 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 23:11:02 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/func.h"

int		ft_bracket_numeric(char **expr)
{
	int nbr;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		nbr = ft_add_sub(expr);
		if (**expr == ')')
			(*expr)++;
		return (nbr);
	}
	return (ft_atoi(expr));
}

int		ft_mul_div_mod(char **expr)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = ft_bracket_numeric(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '*' && op != '/' && op != '%')
			return (nbr);
		(*expr)++;
		nbr2 = ft_bracket_numeric(expr);
		if (op == '*')
			nbr = nbr * nbr2;
		if (op == '/')
			nbr = nbr / nbr2;
		if (op == '%')
			nbr = nbr % nbr2;
	}
	return (nbr);
}

int		ft_add_sub(char **expr)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = ft_mul_div_mod(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op != '-')
			return (nbr);
		(*expr)++;
		nbr2 = ft_mul_div_mod(expr);
		if (op == '+')
			nbr = nbr + nbr2;
		if (op == '-')
			nbr = nbr - nbr2;
	}
	return (nbr);
}

int		eval_expr(char *str)
{
	return (ft_add_sub(&str));
}
