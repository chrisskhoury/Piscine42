/*
 * ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:09:07 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:45:05 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "ft_func.h"

int		char_in_str(char a, char *str)
{
	while (*str)
		if (a == *str++)
			return (1);
	return (0);
}

int		comp_prio(char a, char b)
{
	if (char_in_str(a, "+-") && char_in_str(b, "+-"))	
		return (0);
	if (char_in_str(a, "*/%") && char_in_str(b, "*/%"))	
		return (0);
	if (char_in_str(a, "*/%") && char_in_str(b, "+-"))	
		return (1);
	if (char_in_str(a, "+-") && char_in_str(b, "*/%"))	
		return (-1);
	if (char_in_str(a, "(") || char_in_str(b, "("))	////////??????
		return (-1);	//bcz it should not pop anything below it			////////??????
	return (-2);
}

int		check_prio(t_list **stack, char *oper)
{
	t_list *list;

	list = *stack;
	if (list == NULL)
		return (0);
	if (comp_prio(list->data[0], oper[0]) >= 0)
	{	
		printf("COMPARING ");
		return (1);
	}
	return (0);
}

/*
int main(int argc, char **argv)
{
	t_list *stack;

	stack = NULL;
//	push_to_list(&stack, "+");
	printf("PRIORITY: %d\n",check_prio(&stack, argv[1]));
}*/
