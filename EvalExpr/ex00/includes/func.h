/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 18:20:45 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 23:11:20 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include <unistd.h>
# include <stdio.h>

int		ft_bracket_numeric(char **expr);
int		ft_mul_div_mod(char **expr);
int		ft_add_sub(char **expr);
int		eval_expr(char *expr);
int		ft_atoi(char **str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif
