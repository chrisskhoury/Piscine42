/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 21:58:12 by celias            #+#    #+#             */
/*   Updated: 2018/07/16 21:48:01 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(**range) * (max - min));
	if (*range == 0)
		return (0);
	i = 0;
	while (min + i < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
