/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:00:36 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 16:29:05 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_eq(char *msg)
{
	ft_printf(2, "%s", msg);
	exit(1);
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
		ft_parse(tmp);
		free(tmp);
	}
	else
		ft_parse(argv);
	return (ret);
}