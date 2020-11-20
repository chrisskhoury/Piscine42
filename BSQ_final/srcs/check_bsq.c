/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:21:29 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 22:08:36 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mhead.h"

t_u32	get_height(char *str)
{
	char	*size_nbr;
	int		size_str;
	int		i;
	t_u32	s;

	size_str = ft_strlen(str);
	size_nbr = (char *)malloc(sizeof(char) * (size_str - 2));
	i = -1;
	while (++i < size_str - 3)
	{
		size_nbr[i] = str[i];
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	size_nbr[i] = '\0';
	s = ft_atoi(size_nbr);
	return (s);
}

char	*get_info(char *str)
{
	char	*info;
	int		size;

	if (!(info = (char*)malloc(sizeof(char) * 4)))
		return (0);
	size = ft_strlen(str);
	info[0] = str[size - 3];
	info[1] = str[size - 2];
	info[2] = str[size - 1];
	info[3] = '\0';
	return (info);
}

int		check_bsq(char *av, int file)
{
	char	**lines;
	char	*info;
	t_u32	**grid;
	t_u32	height;
	t_u32	width;

	file = 0;
	if (av)
	{
		file = open(av, O_RDONLY);
		if (file == -1)
			return (0);
	}
	lines = read_stdin(file);
	if (close(file) == -1)
		return (0);
	if (!(height = get_height(lines[0])))
		return (0);
	info = get_info(lines[0]);
	if (!(grid = (t_u32**)malloc(sizeof(t_u32*) * (height - 1))))
		return (0);
	if (!(width = check_array(lines, grid, info, height)))
		return (0);
	free(grid);
	return (1);
}
