/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:49:41 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 15:51:57 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap2(t_list **list1, t_list **list2)
{
	void	*data;

	data = (*list1)->data;
	(*list1)->data = (*list2)->data;
	(*list2)->data = data;
}

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*tmp;

	cur = *begin_list;
	tmp = *begin_list;
	if (!cur)
		return ;
	while (cur->next)
	{
		tmp = *begin_list;
		while (tmp->next)
		{
			if (cmp(tmp->data, tmp->next->data) > 0)
				ft_swap2(&tmp, &(tmp->next));
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

void	ft_list_merge2(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	list = *begin_list1;
	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	while (list->next)
	{
		list = list->next;
	}
	list->next = begin_list2;
}

void	ft_sorted_list_merge(
		t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge2(begin_list1, begin_list2);
	ft_list_sort2(begin_list1, cmp);
}
