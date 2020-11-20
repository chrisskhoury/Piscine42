/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 00:43:04 by celias            #+#    #+#             */
/*   Updated: 2018/07/18 23:12:03 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int stat;

	i = -1;
	stat = 0;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (stat == -1)
				return (0);
			stat = 1;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (stat == 1)
				return (0);
			stat = -1;
		}
	return (1);
}
