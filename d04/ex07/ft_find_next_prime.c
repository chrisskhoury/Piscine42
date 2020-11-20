/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 12:45:56 by celias            #+#    #+#             */
/*   Updated: 2018/07/07 14:54:55 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb == 2147483647)
		return (1);
	else if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else
		while (i * i <= nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
