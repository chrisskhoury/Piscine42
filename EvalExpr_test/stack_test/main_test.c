/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:44:54 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:06:58 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int     push_to_list(t_list **stack, char *data);
int     push_to_list_test(t_list **stack, char *data);
char    *pop_from_stack(t_list **stack);
void    print_stack(t_list *stack);
t_list  *ft_create_elem(char *data);

int		main()
{
	t_list *stack;

	stack = NULL;	
	//stack = ft_create_elem("HI");
	push_to_list(&stack, "hello");
	push_to_list(&stack, "how");
	push_to_list(&stack, "are");
	push_to_list(&stack, "you");
	push_to_list(&stack, "fuck");
	pop_from_stack(&stack);

	print_stack(stack);
//	print_stack(stack);
	
}
