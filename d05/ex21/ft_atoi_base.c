/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:19:52 by celias            #+#    #+#             */
/*   Updated: 2018/07/11 01:29:16 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_value(char c, char *base)
{
	int index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int		ft_atoi(char *str, char *base, int base_size)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str < 32 || *str > 126)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (get_value(*str, base) != -1)
	{
		nb = (base_size * nb) + get_value(*str, base);
		str++;
	}
	return (sign * nb);
}

int		ft_check_base(char *base, int size)
{
	int		i;
	char	search;

	if (size < 2)
		return (0);
	size = 0;
	while (base[size] != '\0')
	{
		if (base[size] == '-' || base[size] == '+'
				|| base[size] < 33 || base[size] > 126)
			return (0);
		i = size;
		search = base[size];
		while (base[++i] != '\0')
		{
			if (search == base[i])
				return (0);
		}
		size++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int base_size;
	int number;
	int index;
	int str_size;

	index = 0;
	number = 0;
	base_size = 0;
	str_size = 0;
	while (str[str_size] != '\0')
		str_size++;
	if (!str_size)
		return (0);
	while (base[base_size] != '\0')
		base_size++;
	if (ft_check_base(base, base_size))
		return (ft_atoi(str, base, base_size));
	else
		return (0);
}

int		main()
{
	printf("%d\n", ft_atoi_base("2a", "0123456789ABCDEF"));
}
