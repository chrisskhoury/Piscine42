/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:40:35 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/15 00:15:14 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_STRUCT_H__
# define __FT_STRUCT_H__


typedef	struct	s_square
{
	char	*posb;
	int		length;
	int		mode;
}				t_square;


//#include "check_posb.c"
//#include "rm_posb.c"

int				rm_posb(char *posb, int length, char delt);

void    		check_col(t_square **board, int x, int y);

void    		check_row(t_square **board, int x, int y);

void			check_box(t_square **board, int row, int col);

#endif
