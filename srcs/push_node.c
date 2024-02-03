/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:58:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/03 15:55:16 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rev_both(t_stack *a, t_stack *b, t_node *to_push, t_list **ret)
{
	while (to_push->data->cost_a < 0 && to_push->data->cost_b < 0)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rrr(a, b)));
		to_push->data->cost_a++;
		to_push->data->cost_b++; 
	}
}

void ft_both(t_stack *a, t_stack *b, t_node *to_push, t_list **ret)
{
	while (to_push->data->cost_a > 0 && to_push->data->cost_b > 0)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rr(a, b)));
		to_push->data->cost_a--;
		to_push->data->cost_b--; 
	}
}

void ft_rotate_a(t_stack *a, t_node *to_push, t_list **ret)
{
	while (to_push->data->cost_a)
	{
		if (to_push->data->cost_a > 0)
		{
			ft_lstadd_back(ret, ft_lstnew(ft_ra(a)));
			to_push->data->cost_a--;
		}
		else if (to_push->data->cost_a < 0)
		{
			ft_lstadd_back(ret, ft_lstnew(ft_rra(a)));
			to_push->data->cost_a++;
		}
	}
}

void ft_rotate_b(t_stack *b, t_node *to_push, t_list **ret)
{
	while (to_push->data->cost_b)
	{
		if (to_push->data->cost_b > 0)
		{
			ft_lstadd_back(ret, ft_lstnew(ft_rb(b)));
			to_push->data->cost_b--;
		}
		else if (to_push->data->cost_b < 0)
		{
			ft_lstadd_back(ret, ft_lstnew(ft_rrb(b)));
			to_push->data->cost_b++;
		}
	}
}

void	ft_prepare_stacks(t_stack *stack_a, t_stack *stack_b, \
		t_node *to_push, t_list **ret)
{
	if (to_push->data->cost_a < 0 && to_push->data->cost_b < 0)
		ft_rev_both(stack_a, stack_b, to_push, ret);
	else if (to_push->data->cost_a > 0 && to_push->data->cost_b > 0)
		ft_both(stack_a, stack_b, to_push, ret);
	ft_rotate_a(stack_a, to_push, ret);
	ft_rotate_b(stack_b, to_push, ret);
}

/*static void	ft_push_node2(t_stack *stack_a, t_stack *stack_b, \
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
		ft_lstadd_back(ret, ft_lstnew(ft_ra(stack_a)));
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	}
	else if (to_push->data->index == stack_a->size - 1)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	}
	else	
		ft_push_node2(stack_a, stack_b, to_push, ret);	
}*/
