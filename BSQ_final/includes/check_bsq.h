/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bsq.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:19:10 by cel-khou          #+#    #+#             */
/*   Updated: 2018/07/25 21:44:21 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BSQ_H
# define CHECK_BSQ_H

t_u32	get_height(char *str);
char	*get_info(char *str);
int		check_bsq(char *av, int f);
void	transform_grid(char **lines, t_u32 **grid, char *info, t_u32 ro_la[4]);
t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height);

#endif
