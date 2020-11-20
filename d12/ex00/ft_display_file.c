/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 12:05:51 by celias            #+#    #+#             */
/*   Updated: 2018/07/26 12:55:28 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	read_file(int file)
{
	char	buffer[1];

	while (read(file, buffer, 1) > 0)
	{
		ft_putchar(*buffer);
	}
}

int main(int ac, char **av)
{
	int file;

	file = 0;
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		if (file == -1)
			return (0);
		read_file(file);
	if (close(file) == -1)
		return (0);
	}
	else
	write(2, "Too many arguments.\n", 20);
}
