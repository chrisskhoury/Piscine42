/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:12:45 by cel-khou          #+#    #+#             */
/*   Updated: 2018/07/25 21:14:53 by cel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

int		count_lines(t_list *begin_list);
char	*get_line(t_list **begin_list);
char	**get_lines(t_list *begin_list);
char	**read_stdin(int file);

#endif
