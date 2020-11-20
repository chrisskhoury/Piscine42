/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 23:17:20 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 19:43:10 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
#include "ft_str.h"
#include "types.h"

int		count_lines(t_list *begin_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = begin_list;
	while (current != NULL)
	{
		if (current->data == '\n')
			count++;
		current = current->next;
	}
	return (count);
}

char	*get_line(t_list **begin_list)
{
	int		i;
	int		len;
	char	*line;
	t_list	*current;

	len = 0;
	current = *begin_list;
	while (current != NULL)
	{
		if (current->data == '\n')
			break ;
		len++;
		current = current->next;
	}
	line = (char *)malloc(sizeof(*line) * (len + 1));
	i = 0;
	while (i <= len)
	{
		line[i++] = (*begin_list)->data;
		current = *begin_list;
		*begin_list = current->next;
		free(current);
	}
	line[len] = '\0';
	return (line);
}

char	**get_lines(t_list *begin_list)
{
	int		i;
	int		new_lines;
	char	**lines;

	new_lines = count_lines(begin_list);
	if (new_lines == 0)
		return (NULL);
	if (!(lines = (char **)malloc(sizeof(*lines) * (new_lines + 1))))
		return (NULL);
	i = 0;
	lines[new_lines] = 0;
	while (i < new_lines)
	{
		lines[i] = get_line(&begin_list);
		i++;
	}
	return (lines);
}

char	**read_stdin(int file)
{
	char	buffer[1];
	t_list	*begin_list;
	t_list	*end_list;
	t_list	*elem;

	begin_list = NULL;
	end_list = NULL;
	while (read(file, buffer, 1) > 0)
	{
		if (!(elem = (t_list *)malloc(sizeof(*elem))))
			return (NULL);
		elem->next = NULL;
		elem->data = *buffer;
		if (begin_list == NULL)
			begin_list = elem;
		else if (end_list != NULL)
			end_list->next = elem;
		end_list = elem;
	}
	return (get_lines(begin_list));
}

void	print_grid(char **lines)
{
	int i;
	int j;

	i = 1;	
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
			printf("%c", lines[i][j++]);
		printf("\n");
		i++;
	}

}

t_u32		get_height1(char *str)
{
	char	*size_nbr;
	int		size_str;
	int		i;
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
	t_u32 s = ft_atoi(size_nbr);
	return (s);
}

char	*get_info(char *str)
{
	char *info;
	int size;

	if(!(info = (char*)malloc(sizeof(char) * 4)))
			return (0);
	size = ft_strlen(str);
	info[0] = str[size - 3];	//empty
	info[1] = str[size - 2];	//obstacle
	info[2] = str[size - 1];	//full
	info[3] = '\0';			//null
	return (info);
}

t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height);

int		main(int ac, char **av)
{
	char	**lines;
	char	*info;
	int		file;
	t_u32	**grid;
	t_u32	height;
	t_u32	width;
	if (ac == 1)
		file = 0;
	else
	{
		file = open(av[1], O_RDONLY);
		printf("file: %d\n", file);
		if (file == -1)
		{
			printf("ERROR OPENING FILE\n");
			return (1);
		}
	}
	lines = read_stdin(file);
	height = get_height1(lines[0]);
	info = get_info(lines[0]);
	printf("height: %d\n", height);
	printf("empty: %c\n", info[0]);
	printf("obstacle: %c\n", info[1]);
	printf("full: %c\n", info[2]);
	print_grid(lines);
	printf("---------\n");
	grid = (t_u32**)malloc(sizeof(t_u32*) * (height -1 ));
	width = check_array(lines, grid, info, height);
}
