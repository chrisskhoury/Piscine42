/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rush_generic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:20:12 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 21:43:28 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checks.h"

t_result	*check_rush_generic(char **tab, char *signs)
{
	int			i;
	t_result	*result;

	if (!(result = (t_result *)malloc(sizeof(*result))))
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	result->height = i;
	i = 0;
	result->width = check_line(tab[i], signs[0], signs[1], signs[2]);
	if (!result->width)
		return (result = NULL);
	while (++i < result->height - 1)
		if (check_line(tab[i], signs[3], signs[4], signs[5]) != result->width)
			return (result = NULL);
	if (i == result->height - 1 &&
			check_line(tab[i], signs[6], signs[7], signs[8]) != result->width)
		return (result = NULL);
	return (result);
}

int			check_line(char *str, char left, char mid, char right)
{
	int i;
	int len;

	len = 0;
	while (str[len])
		len++;
	if (str[0] != left)
		return (0);
	if (len > 1 && str[len - 1] != right)
		return (0);
	i = 1;
	while (i < len - 1)
	{
		if (str[i] != mid)
			return (0);
		i++;
	}
	return (len);
}
