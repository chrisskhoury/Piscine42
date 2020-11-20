/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:51:08 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:42:45 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

t_list				*ft_create_elem(char *data);
int					push_to_list(t_list **stack, char *data);
char				*pop_from_stack(t_list **stack);
void				print_stack(t_list *stack);
int					push_to_stack(t_list **stack, char *data, char **postfix,
					int *cur);
#endif
