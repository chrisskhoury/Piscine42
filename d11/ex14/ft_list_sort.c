/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:39:24 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 15:39:38 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list **list1, t_list **list2)
{
	void	*data;

	data = (*list1)->data;
	(*list1)->data = (*list2)->data;
	(*list2)->data = data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
				ft_swap(&tmp, &(tmp->next));
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}
