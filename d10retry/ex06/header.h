/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 23:49:43 by celias            #+#    #+#             */
/*   Updated: 2018/07/19 01:29:37 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

void			ft_sum(int a, int b);
void			ft_sub(int a, int b);
void			ft_mul(int a, int b);
void			ft_div(int a, int b);
void			ft_mod(int a, int b);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *s);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_check_args(int argc, char **argv);

#endif
