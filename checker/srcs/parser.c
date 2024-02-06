/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:15:46 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/06 18:41:01 by mgovinda         ###   ########.fr       */
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
		return (s1[i] - s2[i]);
	}
	else
		return (-256);
}

void	ft_error(t_stack *a, t_stack *b)
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
	if (!ft_strcmp(line, "pa\n"))
		ft_pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_pb(a, b);
	else if (!ft_strcmp(line, "sa\n"))
		ft_sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(a, b);
	else
		ft_error(a, b);
	free(line);
}

t_stack	*ft_init_b(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		ft_error(a, b);
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
	b->max_size = a->size;
	return (b);
}