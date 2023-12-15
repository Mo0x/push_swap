/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:00:36 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 17:22:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_eq(char *msg)
{
	ft_printf(2, "%s", msg);
	exit(1);
}
static t_dlist	*ft_parse(char **argv)
{
	t_dlist	*ret;
	t_dlist	*tmp;
	int		i;

	i = 2;
	ret = ft_dlstnew(ft_atoi(argv[1]));
	if (!ret)
	while (argv[i])
	{
		tmp = ft_dlstnew(ft_atoi(argv[i++]));
		ft_eq("Error malloc")
		ft_dlst_add_back(&ret, tmp);
	}
	return (ret);
}

t_dlist	*ft_arg_parser(int argc, char **argv)
{
	t_dlist	*ret;
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1]);
		if (!tmp)
			ft_eq("Error when tring to split argv");
		ret = ft_parse(tmp);
		free(tmp);
	}
	else
		ret = ft_parse(argv);
	return (ret);
}