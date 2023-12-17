/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:00:36 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/17 19:13:56 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static t_stack	*ft_parse(char **argv, int starting)
{
	t_stack	*ret;
	t_node	*tmp;
	int		i;

	i = starting + 1;
	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->head = ft_dlst_new(ft_atoi(argv[starting]));
	ret->size = 1;
	if (!ret)
		ft_eq("Error malloc");
	while (argv[i])
	{
		tmp = ft_dlst_new(ft_atoi(argv[i++]));
		ft_dlst_add_back(&ret->head, tmp);
		ret->size += 1;
	}
	ret->tail = ft_dlst_last(ret->head);
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