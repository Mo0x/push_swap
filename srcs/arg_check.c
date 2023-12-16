/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:29:41 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/16 18:22:18 by mgovinda         ###   ########.fr       */
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
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

void ft_arg_checker(int argc, char **argv, int index)
{
	int	j;
	int	i;

	i = index - 1;
	while (++i < argc)
	{
		if (ft_strdigit(argv[i]) == 0 || !argv[i][0] || ft_atoll(argv[i]) > INT_MAX \
			|| ft_atoll(argv[i]) < INT_MIN)
		{
			ft_printf(2, "Error\n");
			exit(-1);
		}
	}
	i = index - 1;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf(2, "Error\n");
				exit(-1);
			}
	}
}

void	ft_arg_check_split(char **argv)
{
	char	**tmp;
	int		ac;

	ac = 0;
	tmp = ft_split_wc(argv[1], ' ', &ac);
	if (!tmp)
		exit(1);
	if (ft_strcmp(tmp[0], argv[1]) == 0)
	{
		if (ft_atoll(argv[1]) > INT_MAX || ft_atoll(argv[1]) < INT_MIN)
			exit(0);
		else
			ft_eq("Error\n");
	}
	ft_arg_checker(ac, argv, 0);
}