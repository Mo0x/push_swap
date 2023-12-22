/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/22 17:42:16 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pricing(t_stack *stack)
{
	t_node *node;

	node = stack->head;
	while (node)
	{
		if (node->data->index == 0)
			node->data->cost = 1;
		else if (node->data->index == 1 || node->data->index == (stack->size) -1)
			node->data->cost = 2;
		else
		{
			if (node->data->index < (stack->size / 2) + 1)
				node->data->cost = node->data->index + 1;
			else
				node->data->cost = (stack->size - node->data->index) + 1;
		}
		node = node->next;
	}
}


void	ft_push_node(t_stack *stack_a, t_stack *stack_b, t_node *to_push)
{
	int	i;

	if (to_push->data->index == 0)
		ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	else if (to_push->data->index == 1)
	{
		ft_putendl_fd(ft_sa(stack_a), 1);
		ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	}
	else if (to_push->data->index == stack_a->size - 1)
	{
		ft_putendl_fd(ft_rra(stack_a), 1);
		ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	}
	else
	{
		if (to_push->data->index < (stack_a->size / 2) + 1)
		{ 
			i = to_push->data->index;
			while (i-- > 0)
				ft_putendl_fd(ft_ra(stack_a), 1);
		}
		else
		{
			i = (stack_a->size - to_push->data->index);
			while (i-- > 0)
				ft_putendl_fd(ft_rra(stack_a), 1);
		}
		ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	}
}

void	ft_push_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		cost;
	int		layer;
	int		to_push;

	cost = 2147483647;
	layer = 99;
	tmp = stack_a->head;
	while (tmp)
	{
		if (tmp->data->layer < layer)	
			layer = tmp->data->layer;
		tmp = tmp->next;
	}
	tmp = stack_a->head;
	while (tmp)
	{
		if (tmp->data->cost < cost && layer == tmp->data->layer)
		{
			cost = tmp->data->cost;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_a, to_push);
	ft_push_node(stack_a, stack_b, tmp);
}

void	ft_push_back(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->head)
	{
		ft_pricing(stack_a);
		ft_push_cheapest(stack_a, stack_b);
	}
	ft_pricing(stack_b);
}
