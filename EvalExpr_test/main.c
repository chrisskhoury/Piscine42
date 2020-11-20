/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 03:18:29 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 20:37:54 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_func.h"
#include "ft_list.h"

int		ft_tablen(char **tab)
{
	int size;

	size = 0;
	while (*(tab + size))
		size++;
	return (size);
}

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*(str + size))
		size++;
	return (size);
}

int		is_numeric(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
		return (1);
}

int		is_operator(char *str)
{
	char *operators;
	int i;

	i = -1;
	operators = "+-*/%()";
	if (ft_strlen(str) != 1)
		return (0);
	while (operators[++i])
		if (str[0] == operators[i])
			return (i + 1);
	return (0);
}
char	*ft_strdup(char *src)
{
	int		size;
	char	*des;

	size = 0;
	while (src[size] != '\0')
		size++;
	des = (char *)malloc(size + 1);
	if (des == 0)
		return (0);
	size = 0;
	while (src[size] != '\0')
	{
		des[size] = src[size];
		size++;
	}
	des[size] = '\0';
	return (des);
}

char	**generate_postfix(t_list **stack, char **pre)
{
	char **postfix;
	int i;
	int cur;

	printf("LENGTH OF TAB: ------ %d ------", ft_tablen(pre));
	if (!(postfix = (char**)malloc(sizeof(*postfix) * (ft_tablen(pre) + 1))))
		return (0);
	i = 0;
	cur = 0;
	while (pre[i])
	{
		if (is_numeric(pre[i]))
		{
			printf("IT IS A NUMBER : %s\n", pre[i]);
			postfix[cur++] = ft_strdup(pre[i]);
		}
			else if (is_operator(pre[i]))
		{
			printf("iT IS AN OPERATOR : %s\n", pre[i]);
			push_to_stack(stack, pre[i], postfix, &cur);
			//push_to_list(stack, pre[i]);
			print_stack(*stack);
		}
			i++;
	}
	
	while (*stack)
	{
		postfix[cur++] = pop_from_stack(stack);
		printf("CURRENT _________ %d ________, cur");
	}
	postfix[cur] = 0;
	return (postfix);
}

int		main(int argc, char **argv)
{
	char **s;
	t_list *stack;

	stack = NULL;
	s = generate_postfix(&stack, ft_str_to_tab(argv[1]));

	while (*s)
	{
		printf("%s\n", *s);
		s++;
	}
}
