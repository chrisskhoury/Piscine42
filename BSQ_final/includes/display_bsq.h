/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bsq.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:32:35 by cel-khou          #+#    #+#             */
/*   Updated: 2018/07/25 21:34:51 by cel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_BSQ_H
# define DISPLAY_BSQ_H

void	print_solution(char **grid, t_u32 height, t_u32 width);
void	transform_grid(char **lines, t_u32 **grid, char *info, t_u32 ro_la[4]);

#endif
