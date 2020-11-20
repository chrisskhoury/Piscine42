/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:03:42 by celias            #+#    #+#             */
/*   Updated: 2018/07/26 12:17:54 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mhead.h"
#include "check_bsq.h"
#include "ft_read.h"

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		check_bsq(0, 0);
	else
		while (++i < ac)
		{
			if (!(check_bsq(av[i], 0)))
				write(2, "map error\n", 10);
			write(1, "\n", 1);
		}
}
