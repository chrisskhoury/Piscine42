/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 02:23:08 by celias            #+#    #+#             */
/*   Updated: 2018/07/13 04:57:16 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_low_found_it(char *str, char *to_find)
{
	int i;
	int j;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (to_find[j] == str[i])
		{
			while (to_find[j] == str[i + j])
			{
				j++;
				if (to_find[j] == '\0')
					return (1);
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		is_danger(char *str)
{
	if (ft_strcmp(str, "president") == 0
			|| ft_strcmp(str, "attack") == 0
			|| ft_strcmp(str, "bauer") == 0)
		return (1);
	return (0);
}

char	*ft_strip(char *str)
{
	int i;
	int j;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	i = 0;
	j = 0;
	while (str[i + j] != '\0')
		if (str[i + j] == 32 || (str[i + j] >= 9 && str[i + j] <= 13))
		{
			str[i + j] = '\0';
			j++;
		}
		else
		{
			str[i] = str[i + j];
			i++;
		}
	str[i] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	char *str;

	str = "Alert!!!\n";
	while (--argc > 0)
		if (ft_low_found_it(argv[argc], "president")
				|| ft_low_found_it(argv[argc], "attack")
				|| ft_low_found_it(argv[argc], "bauer"))
			if (is_danger(ft_strip(argv[argc])))
				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
				}
	return (0);
}
