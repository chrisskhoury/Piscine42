/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:14:03 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 12:02:32 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str)
{
	int i;
	int j;
	int word_count;

	word_count = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		while (!(str[i + j] == ' ' || str[i + j] == '\n' ||
					str[i + j] == '\t' || str[i + j] == 0))
		{
			if (j == 0)
				word_count++;
			j++;
		}
		i += j;
	}
	return (word_count);
}

char	**check_null(char **no_whites, int cur)
{
	no_whites[cur] = 0;
	return (no_whites);
}

char	**fill_no_whites(char **no_whites, char *str, int i, int j)
{
	int cur;
	int k;

	cur = 0;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] == '\0')
			return (check_null(no_whites, cur));
		while (!(str[i + k] == ' ' || str[i + k] == '\n' ||
					str[i + k] == '\t' || str[i + k] == 0))
			k++;
		no_whites[cur] = (char*)malloc((sizeof(**no_whites) * (k + 1)));
		j = -1;
		while (++j < k)
			no_whites[cur][j] = str[i + j];
		no_whites[cur++][j] = '\0';
		i += k;
	}
	no_whites[cur] = 0;
	return (no_whites);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	char	**no_whites;

	i = 0;
	j = 0;
	no_whites = (char**)malloc(sizeof(*no_whites) * (count_words(str) + 2));
	return (fill_no_whites(no_whites, str, i, j));
}
