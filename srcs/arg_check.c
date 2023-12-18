/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:29:41 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 16:00:50 by mgovinda         ###   ########.fr       */
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
	if ((str[0] == '-' || str[0] == '+') && ft_isdigit(str[1]) && str[1])
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

void	ft_arg_checker_split(char **argv)
{
	char	**tmp;
	int		ac;

	ac = 0;
	if (!argv[1][0])
		ft_eq("Error\n");
	tmp = ft_split_wc(argv[1], ' ', &ac);
	if (!tmp)
		exit(1);
	if (ft_strcmp(tmp[0], argv[1]) == 0)
	{
		if (ft_strdigit(argv[1]) == 0 || !argv[1][0] || ft_atoll(argv[1]) > INT_MAX \
			|| ft_atoll(argv[1]) < INT_MIN)
			ft_eq("Error\n");
		else
			exit(0);
	}
	ft_arg_checker(ac, tmp, 0);
	ft_free_tab(tmp);
}

void	ft_arg_init(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	else if (argc == 2)
		ft_arg_checker_split(argv);
	else
		ft_arg_checker(argc, argv, 1);
}