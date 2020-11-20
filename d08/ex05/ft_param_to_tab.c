/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:13:30 by celias            #+#    #+#             */
/*   Updated: 2018/07/17 19:49:06 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (*(str + size) != '\0')
		size++;
	return (size);
}

char				*ft_strdup(char *src)
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

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*stock;
	t_stock_par last;

	last.str = 0;
	last.copy = 0;
	last.tab = 0;
	last.size_param = 0;
	stock = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		stock[i].size_param = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stock[i] = last;
	return (stock);
}
