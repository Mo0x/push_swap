/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:00:36 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/16 17:22:46 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_eq(char *msg)
{
	ft_printf(2, "%s", msg);
	exit(1);
}

static void	*ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static t_stack	*ft_parse(char **argv, int starting)
{
	t_stack	*ret;
	t_dlist	*tmp;
	int		i;

	i = starting + 1;
	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->head = ft_dlst_new(ft_atoi(argv[starting]));
	if (!ret)
		ft_eq("Error malloc");
	while (argv[i])
	{
		tmp = ft_dlst_new(ft_atoi(argv[i++]));
		ft_dlst_add_back(&ret->head, tmp);
	}
	return (ret);
}

t_stack	*ft_arg_parser(int argc, char **argv)
{
	t_stack	*ret;
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			ft_eq("Error when tring to split argv");
		ret = ft_parse(tmp, 0);
		ft_free_tab(tmp);
	}
	else
		ret = ft_parse(argv, 1);
	return (ret);
}