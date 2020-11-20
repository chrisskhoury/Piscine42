/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:52:50 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 23:45:51 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	tmp = 0;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->next = 0;
		tmp->data = data;
	}
	return (tmp);
}
