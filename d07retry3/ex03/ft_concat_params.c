/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:48:47 by celias            #+#    #+#             */
/*   Updated: 2018/07/18 15:29:37 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*str;

	i = 1;
	k = 0;
	size = 0;
	while (i < argc)
		size = size + ft_strlen(argv[i++]) + 1;
	str = malloc(sizeof(char) * size);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			str[k++] = argv[i][j++];
		if (i < argc - 1)
			str[k++] = '\n';
		else
			str[k++] = '\0';
		i++;
	}
	return (str);
}

int main(int argc, char**argv)
{
	printf("%s", ft_concat_params(argc, argv));
}
