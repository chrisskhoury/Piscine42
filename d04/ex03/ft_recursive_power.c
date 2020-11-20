/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:11:15 by celias            #+#    #+#             */
/*   Updated: 2018/07/06 16:23:16 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (0);
	else if (power > 0)
		return (result *= ft_recursive_power(nb, power - 1));
	else
		return (1);
}
