/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:57:00 by celias            #+#    #+#             */
/*   Updated: 2018/07/22 23:19:53 by gguichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

char			**read_stdin(void);

typedef struct	s_result
{
	int width;
	int height;
}				t_result;

typedef struct	s_check
{
	char		*name;
	t_result	*(*f)(char**);
}				t_check;

t_result		*check_rush_generic(char **tab, char *signs);
t_result		*check_rush00(char **tab);
t_result		*check_rush01(char **tab);
t_result		*check_rush02(char **tab);
t_result		*check_rush03(char **tab);
t_result		*check_rush04(char **tab);

int				check_line(char *str, char left, char mid, char right);

#endif
