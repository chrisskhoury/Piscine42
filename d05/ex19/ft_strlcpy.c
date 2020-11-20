/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:45:23 by celias            #+#    #+#             */
/*   Updated: 2018/07/10 19:22:57 by celias           ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;

	index = 0;
	while (index < size - 1 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < size - 1)
	{
		dest[index] = '\0';
		index++;
	}
	index = 0;
	while (src[index] != '\0')
		index++;
	return (index);
}
