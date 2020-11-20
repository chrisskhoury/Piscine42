/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:40:35 by hmidoun           #+#    #+#             */
/*   Updated: 2018/07/14 23:42:58 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_STRUCT_H__
# define __FT_STRUCT_H__

#include "check_box.c"
#include "rm_posb.c"

int             rm_posb(char *posb, int length, char delt);
void            check_box(t_square **board, int row, int col);

typedef	struct	s_square
{
	char	*posb;
	int		length;
	int		mode;
}				t_square;
#endif
