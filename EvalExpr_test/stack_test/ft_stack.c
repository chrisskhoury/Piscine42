/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 03:50:48 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:06:37 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(char *data)
{
	t_list *tmp;

	tmp = NULL;
	printf("CREATED ELEMENT %s\n", data);
	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (0);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

int		push_to_list(t_list **stack, char *data)
{
	t_list *list;

	if (*stack != NULL)
	{
		list = ft_create_elem(data);
		list->next = *stack;
		*stack = list;
	}
	else
		*stack = ft_create_elem(data);
}

char	*pop_from_stack(t_list **stack)
{
	char *retval = 0;
	t_list *next_t_list = NULL;

	if(*stack == NULL)
		return (0);
	next_t_list = (*stack)->next;
	retval = (*stack)->data;
	free(*stack);
	*stack = next_t_list;

	return (retval);
}

/*
   int		push_to_stack(t_list **stack, char *data, char **postfix, int *cur)
   {
   t_list *list;

   list = *stack;
   printf("CEHCKING STACK\n");
   while (check_prio(&list, data))
   {
   printf("WAnT TO CALL POP");
   postfix[*cur] = pop_from_stack(&list);
 *cur += 1;
 list = list->next;
 } ////DOES NOT HANDLE () YET!!!!!!!
 push_to_list(&list, data);
 printf("PUSHED TO LIST: %s\n", list->data);
//	print_stack(list);
return (1);


}
*/
void	print_stack(t_list *stack)
{
	t_list *current  = stack;
	while (current != 0)
	{
		printf("IN THE STACK : %s    $$$$$\n", current->data);
		current = current->next;
	}
}

