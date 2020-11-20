/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:54:48 by celias            #+#    #+#             */
/*   Updated: 2018/07/25 19:37:44 by cel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
#include "types.h"

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putchar(list->data);
		list = list->next;
	}
}

t_u32	get_lwidth(t_list *list)
{
	t_u32	width;

	width = 0;
	while (list)
	{
		width++;
		list = list->next;
	}
	return (width);
}

char	*list_to_str(t_list *list)
{
	char	*str;
	int		i;

	if (!list)
		return (NULL);
	i = 0;
	if(!(str = (char*)malloc(sizeof(*str) * (get_lwidth(list) + 1))))
		return (NULL);
	while (list)
	{
		str[i++] = list->data;
		list = list->next;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line(int file)
{
	char	buffer[1];
	t_list	*begin_list;
	t_list	*end_list;
	t_list	*elem;

	begin_list = NULL;
	end_list = NULL;
	while (read(file, buffer, 1) > 0 && *buffer != '\n')
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
	return (list_to_str(begin_list));
}

int		main(int ac, char **av)
{
	char	**lines;
	char	*info;
	int		fd;

	fd = open(av[1], O_RDONLY);
	ft_putchar(fd + 48);
	ft_putchar('\n');
	if (fd == -1)
	{
		printf("ERROR OPENING FILE\n");
		return (1);
	}
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
	printf("%s\n", read_line(fd));
}
