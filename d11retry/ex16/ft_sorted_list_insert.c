/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:11:28 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 15:53:04 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back2(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_elem;
	t_list	*list;
	t_list	*tmp;

	if (!(list = *begin_list))
		return ;
	new_elem = ft_create_elem(data);
	if ((cmp(list->data, data) >= 0))
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
		return ;
	}
	while (list->next)
	{
		if ((cmp(list->data, data) < 0) && (cmp(list->next->data, data) >= 0))
		{
			tmp = list->next;
			list->next = new_elem;
			new_elem->next = tmp;
			return ;
		}
		list = list->next;
	}
	ft_list_push_back2(&list, data);
}
