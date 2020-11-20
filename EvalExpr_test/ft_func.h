/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:13:54 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 17:43:24 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNC_H
# define FT_FUNC_H
# include "ft_list.h"
# include <stdio.h>

char	**ft_str_to_tab(char*str);
char 	**split_expr(char *expr);
int     ft_tablen(char **tab);
int     ft_strlen(char *str);
int     is_numeric(char *str);
int     is_operator(char *str);
char    *ft_strdup(char *src);
char    **generate_postfix(t_list **stack, char **pre);
int     check_prio(t_list **stack, char *oper);
#endif
