/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:15:46 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 14:24:11 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
	}	
	return (s1[i] - s2[i]);
}

static void	error(t_stack *a, t_stack *b)
{
	ft_nodes_clear(&(a->head));
	ft_nodes_clear(&(b->head));
	free(a);
	free(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_parser(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(command, "pa\n"))
		ft_pa(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		ft_pb(a, b);
	else if (!ft_strcmp(command, "sa\n"))
		ft_sa(a);
	else if (!ft_strcmp(command, "sb\n"))
		ft_sb(b);
	else if (!ft_strcmp(command, "ss\n"))
		ft_ss(a, b);
	else if (!ft_strcmp(command, "ra\n"))
		ft_ra(a);
	else if (!ft_strcmp(command, "rb\n"))
		ft_rb(b);
	else if (!ft_strcmp(command, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		ft_rra(a);
	else if (!ft_strcmp(command, "rrb\n"))
		ft_rrb(b);
	else if (!ft_strcmp(command, "rrr\n"))
		ft_rrr(a, b);
	else
		error(a, b);
}