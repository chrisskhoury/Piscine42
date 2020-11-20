/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 00:47:42 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 10:38:33 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = -1;
	if (begin_list)
	{
		while (++i != nbr)
		{
			if (!begin_list)
				return (0);
			begin_list = begin_list->next;
		}
		return (begin_list);
	}
	else
		return (0);
}
