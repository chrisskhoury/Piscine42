/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 00:47:21 by celias            #+#    #+#             */
/*   Updated: 2018/07/17 01:03:13 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_size(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (++j < argc)
	{
		k = 0;
		while (argv[j][k++] != '\0')
			i++;
	}
	return (i + 2 * (argc - 2) + 1);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = (char*)malloc(sizeof(*str) * get_size(argc, argv));
	i = 0;
	j = 0;
	k = 0;
	while (++j < argc)
	{
		k = 0;
		while (argv[j][k] != '\0')
			str[i++] = argv[j][k++];
		if (j != argc - 1)
			str[i++] = '\n';
		else
			str[i] = '\0';
	}
	return (&str[0]);
}
