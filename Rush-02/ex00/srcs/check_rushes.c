/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:51:13 by rotessie          #+#    #+#             */
/*   Updated: 2018/07/21 19:54:29 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

t_result	*check_rush00(char **tab)
{
	return (check_rush_generic(tab, "o-o| |o-o"));
}

t_result	*check_rush01(char **tab)
{
	return (check_rush_generic(tab, "/*\\* *\\*/"));
}

t_result	*check_rush02(char **tab)
{
	return (check_rush_generic(tab, "ABAB BCBC"));
}

t_result	*check_rush03(char **tab)
{
	return (check_rush_generic(tab, "ABCB BABC"));
}

t_result	*check_rush04(char **tab)
{
	return (check_rush_generic(tab, "ABCB BCBA"));
}
