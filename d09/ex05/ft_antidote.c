/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:49:27 by celias            #+#    #+#             */
/*   Updated: 2018/07/12 22:58:31 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if ((i < j && i > k) || (i > j && i < k))
		return (i);
	else if ((j < i && j > k) || (j > i && j < k))
		return (j);
	else if ((k < j && k > i) || (k > j && k < i))
		return (k);
	else
		return (j);
}