/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:06:08 by celias            #+#    #+#             */
/*   Updated: 2018/07/09 00:06:01 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (&str[0]);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int cap_next;

	i = 0;
	cap_next = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')
					|| (str[i] >= 'a' && str[i] <= 'z')))
			cap_next = 1;
		else if (((str[i] >= '0' && str[i] <= '9')
					|| (str[i] >= 'a' && str[i] <= 'z'))
					&& cap_next)
		{
			str[i] -= 32;
			cap_next = 0;
		}
		i++;
	}
	return (&str[0]);
}
