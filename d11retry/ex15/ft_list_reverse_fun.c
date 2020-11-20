/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:07:48 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 16:32:44 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap1(void **x, void **y)
{
	void	*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int		ft_list_size1(t_list *begin_list)
{
	int size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*list;

	size = ft_list_size1(begin_list);
	list = begin_list;
	if (size == 1 || size == 0)
		return ;
	i = -1;
	while (++i < size / 2)
	{
		j = i;
		tmp = list->next;
		while (++j < size - i - 1)
			tmp = tmp->next;
		ft_swap1(&(list->data), &(tmp->data));
		list = list->next;
	}
}
