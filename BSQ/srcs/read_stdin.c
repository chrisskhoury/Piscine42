/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/07/22 23:17:20 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 18:45:50 by celias           ###   ########.fr       */
=======
/*   Created: 2018/07/24 13:58:14 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 19:43:54 by cel-khou         ###   ########.fr       */
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
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
#include "ft_check.h"

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
	int		first_line;

	first_line = 1;
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

<<<<<<< HEAD
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
=======
t_u32	get_height1(char *str)
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
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

<<<<<<< HEAD
t_u32	check_array(char **lines, t_u32 **grid, char *info, t_u32 height);
=======
void	print_list(char **grid, t_u32 height)
{
	t_u32	i;
	t_u32	j;

	i = -1;
	j = -1;
	while (grid[i])
	{
		while (grid[i][++j])
		{
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void	print_grid(t_u32 **grid, t_u32 height, t_u32 width)
{
	t_u32	i;
	t_u32	j;

	i = -1;
	j = -1;
	while (++i < height)
	{
		while (++j < width)
		{
			printf("%d  ", grid[i][j]);
		}
		printf("\n");
	}
}
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d

int		main(int ac, char **av)
{
	char	**lines;
	char	*info;
	int		file;
	t_u32	**grid;
	t_u32	height;
<<<<<<< HEAD
	t_u32	width;
=======

>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
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
<<<<<<< HEAD
	printf("height: %d\n", height);
	printf("empty: %c\n", info[0]);
	printf("obstacle: %c\n", info[1]);
	printf("full: %c\n", info[2]);
	print_grid(lines);
	printf("---------\n");
	grid = (t_u32**)malloc(sizeof(t_u32*) * (height -1 ));
	width = check_array(lines, grid, info, height);
=======
>>>>>>> 62bee9335c2f8759a1cf39bbee9c4b5df59ef51d
}
