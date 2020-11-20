/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:01:37 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/23 18:33:53 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_functions.h"
#include "checks.h"
#include "lists.h"

t_check	g_checks[] =
{
	{"colle-00", &check_rush00},
	{"colle-01", &check_rush01},
	{"colle-02", &check_rush02},
	{"colle-03", &check_rush03},
	{"colle-04", &check_rush04},
	{0, (void *)0}
};

void	print_match(char *name, t_result *result)
{
	ft_putstr(name);
	ft_putstr(" [");
	ft_putnbr(result->width);
	ft_putstr("] [");
	ft_putnbr(result->height);
	ft_putstr("]");
}

int		main(void)
{
	int			i;
	int			matches;
	char		**lines;
	t_result	*result;

	i = 0;
	matches = 0;
	lines = read_stdin();
	while (lines != NULL && g_checks[i].name != 0)
	{
		result = g_checks[i].f(lines);
		if (result != NULL)
		{
			if (matches > 0)
				ft_putstr(" || ");
			matches++;
			print_match(g_checks[i].name, result);
		}
		i++;
	}
	if (matches == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
	return (0);
}
