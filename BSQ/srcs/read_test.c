/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 23:17:20 by gguichar          #+#    #+#             */
/*   Updated: 2018/07/25 12:30:46 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

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

char	**read_stdin(void)
{
	char	buffer[1];
	t_list	*begin_list;
	t_list	*end_list;
	t_list	*elem;

	begin_list = NULL;
	end_list = NULL;
	while (read(0, buffer, 1) > 0)
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

void	print_arr(char **lines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lines[i])
	{
		while (lines[i][j])
		{	
			printf("%c", lines[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}

}

int		main()
{
	char **lines;

	lines = read_stdin();
	print_arr(lines);
}
