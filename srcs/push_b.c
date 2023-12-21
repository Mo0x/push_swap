/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/21 17:19:45 by mgovinda         ###   ########.fr       */
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
		else if (node->data->index == 1 || node->data->index == stack->size)
			node->data->cost = 2;
		else
		{
			if (node->data->index < stack->size / 2)
			{
				node->data->cost = node->data->index + 1;
			}
			else
			{
				node->data->cost = (stack->size - node->data->index) + 1;
			}
		}
		node = node->next;
	}
}

void	ft_keep_pushing(t_stack *stack_a, t_stack *stack_b)
{
	ft_pb(stack_a, stack_b);
}

void	ft_push_back(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size)
	{
		ft_pricing(stack_a);
	}
	else
		ft_keep_pushing(stack_a, stack_b);
}
