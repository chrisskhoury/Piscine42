/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:22:25 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 15:42:28 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		list = ft_create_elem(data);
		list->next = *begin_list;
		*begin_list = list;
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*current;

	i = 0;
	current = 0;
	while (i < ac)
	{
		ft_list_push_front(&current, av[i]);
		i++;
	}
	return (current);
}
