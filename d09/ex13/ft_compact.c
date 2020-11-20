/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:45:15 by celias            #+#    #+#             */
/*   Updated: 2018/07/13 16:42:39 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int i;
	int new_len;

	new_len = length;
	i = 0;
	while (i < length)
	{
		if (tab[i] == 0)
		{
			tab[i] = tab[i + 1];
			i++;
			new_len--;	
		}
		i++;
	}
	return (new_len);
}
