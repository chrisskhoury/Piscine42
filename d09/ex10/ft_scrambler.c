/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:11:46 by celias            #+#    #+#             */
/*   Updated: 2018/07/13 05:15:42 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmp;

	tmp = ***a;
	***a = *b;
	*b = ****d;
	****d = *******c;
	*******c = tmp;
}
