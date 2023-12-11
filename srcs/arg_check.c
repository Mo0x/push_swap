/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:29:41 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/11 16:38:38 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_strdigit(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

void arg_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (ft_strdigit(argv[i]) == 0 || !argv[i][0] || ft_atoll(argv[i]) > INT_MAX \
			|| ft_atoll(argv[i]) < INT_MIN)
		{
			ft_printf(2, "Error\n");
			exit(-1);
		}
	}
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (!ft_strcmp(argv[i], argv[j]))
			{
				ft_printf(2, "Error\n");
				exit(-1);
			}
	}
}