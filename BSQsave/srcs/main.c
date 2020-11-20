/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:03:42 by celias            #+#    #+#             */
/*   Updated: 2018/07/23 19:10:27 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "ft_list.h"

#define BUF_SIZE 4096

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("OPEN ERROR\n");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	printf("ret: %d, buf: %s\n", ret ,buf);
	if (close(fd) == -1)
	{
		printf("CLOSE ERROR\n");
		return (1);
	}
	return (0);
}
