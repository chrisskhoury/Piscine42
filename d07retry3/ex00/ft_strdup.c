/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:21:26 by celias            #+#    #+#             */
/*   Updated: 2018/07/16 21:50:02 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*des;

	size = 0;
	while (src[size] != '\0')
		size++;
	des = (char *)malloc(size + 1);
	if (des == 0)
		return (0);
	size = 0;
	while (src[size] != '\0')
	{
		des[size] = src[size];
		size++;
	}
	des[size] = '\0';
	return (des);
}
