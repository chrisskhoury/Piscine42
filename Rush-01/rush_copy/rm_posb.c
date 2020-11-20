/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:38:44 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/14 23:42:40 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int				rm_posb(char *posb, int length, char delt)
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (posb[i] == delt)
		{
			while (i < length)
			{
				posb[i] = posb[i + 1];
				i++;
			}
			length--;
			break ;
		}
		i++;
	}
	return (length);
}
