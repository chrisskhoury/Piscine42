/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 03:17:03 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:16:12 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    **ft_allocate_number_of_str(char *str)
{
	int             i;
	int             j;
	char    **word;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || str[i] == '\n'
					|| str[i] == '\t' || str[i] == '\0'))
		{
			if ((str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t'))
				j++;
		}
		if (str[i] == '(' || str[i] == ')')      //counting brackets
			j++;
		i++;
	}
	if (str[0] == ' ' || str[0] == '\n' || str[0] == '\t')
		j--;
	word = (char**)malloc(sizeof(char *) * (j + 4));
	return (word);
}

int             ft_nbr_char(char *str)
{
	int             cnt;

	cnt = 0;
	while (*str != ' ' && *str != '\n' && *str != '\t' && *str != '\0' && *str != '(' && *str != ')')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char    **ft_str_to_tab(char *str)
{
	char    **word;
	int             i;
	int             j;
	int             cnt;

	word = ft_allocate_number_of_str(str);
	i = 0;
	while (*str != '\0')
	{
		j = 0;
		cnt = 0;
		if (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		if (*str != ' ' && *str != '\n' && *str != '\t' && *str != '\0')
		{
			while (*str == '(' || *str == ')')
			{
				word[i] = (char*)malloc(sizeof(char) * 2);
				word[i][j++] = *str++;
				word[i++][j] = '\0';
				j = 0;
			}
			if (*str == ' ' || *str == '\n' || *str == '\t')
				str++;
			cnt = ft_nbr_char(str);
			word[i] = (char*)malloc(sizeof(char) * (cnt + 1));
			while (*str != ' ' && *str != '\n' && *str != '\t' && *str != '\0' && *str != ')')
				word[i][j++] = *str++;
			word[i++][j] = '\0';
		}
	}
	word[i] = 0;
	return (word);
}
