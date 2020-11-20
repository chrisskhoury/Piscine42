/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:44:16 by cel-khou          #+#    #+#             */
/*   Updated: 2018/07/25 22:16:24 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include "types.h"
# include "lists.h"

t_u32		ft_min(t_u32 top, t_u32 top_left, t_u32 left);

t_u32		check_line(char *line, t_u32 **grid,
						char *info, t_u32 (*ro_la)[5]);

t_u32		check_array(char **lines, t_u32 **grid, char *info, t_u32 height);

#endif
