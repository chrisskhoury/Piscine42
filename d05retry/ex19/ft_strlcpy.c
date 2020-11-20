/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:45:23 by celias            #+#    #+#             */
/*   Updated: 2018/07/11 17:10:20 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*d;
	const char		*s;
	unsigned int	n;

	d = dest;
	s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*d++ = *s++) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
