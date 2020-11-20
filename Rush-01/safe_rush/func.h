/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:40:35 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 13:33:53 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#ifndef __FT_FUNC_H__
#define __FT_FUNC_H__
#define S_SIZE 9
int				rm_posb(char *posb, int length, char delt);

int				check_col(int **board, int x, int y);

int				check_row(int **board, int x, int y);

int				check_box(int **board, int x, int y);

int				check_all(int **board, int x, int y);

int				check_argv(int argc, char **argv);

void			create_board(char **argv, int **board);

int				ft_strlen(char *str);

int				is_numeric_point(char *str);



#endif
