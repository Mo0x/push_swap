/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:58:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/02 17:17:55 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_node2(t_stack *stack_a, t_stack *stack_b, \
		t_node *to_push, t_list **ret)
{
	int i;

	if (to_push->data->index < (stack_a->size / 2) + 1)
	{
		i = to_push->data->index;
		while (i-- > 0)
			ft_lstadd_back(ret, ft_lstnew(ft_ra(stack_a)));
	}
	else
	{
		i = (stack_a->size - to_push->data->index);
		while (i-- > 0)
			ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
	}
	ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
}

void	ft_push_node(t_stack *stack_a, t_stack *stack_b, \
		t_node *to_push, t_list **ret)
{
	if (to_push->data->index == 0)
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	else if (to_push->data->index == 1)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_sa(stack_a)));
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	}
	else if (to_push->data->index == stack_a->size - 1)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	}
	else	
		ft_push_node2(stack_a, stack_b, to_push, ret);	
}
