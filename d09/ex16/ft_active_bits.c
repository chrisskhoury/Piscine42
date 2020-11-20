/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:43 by celias            #+#    #+#             */
/*   Updated: 2018/07/13 15:47:00 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	int counter;

	counter = 0;
	while (value)
	{
		counter++;
		value &= (value - 1);
	}
	return (counter);
}
