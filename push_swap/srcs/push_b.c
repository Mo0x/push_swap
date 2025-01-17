/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/10 13:27:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_pricing_to_b(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->data->index > (stack->size / 2) + 1)
			node->data->cost_a = (stack->size - node->data->index) * -1;
		else
			node->data->cost_a = node->data->index;
		node = node->next;
	}
}


/*void	ft_pricing_to_b(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->data->index == 0)
			node->data->cost = 1;
		else if (node->data->index == 1 || \
			node->data->index == (stack->size) - 1)
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
}*/

void	ft_push_cheapest_layered(t_stack *stack_a, \
		t_stack *stack_b, t_list **ret)
{
	t_node	*tmp;
	int		cost;
	int		layer;
	int		to_push;

	cost = INT_MAX;
	layer = ft_lowest_layer(stack_a);
	tmp = stack_a->head;
	while (tmp)
	{
		if (ft_abs(tmp->data->cost_a) < cost && layer == tmp->data->layer)
		{
			cost = tmp->data->cost_a;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_a, to_push);
	ft_prepare_stacks(stack_a, stack_b, tmp, ret);
	ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
}

void	ft_push_cheapest(t_stack *stack_a, t_stack *stack_b, t_list **ret)
{
	int		cost;
	int		to_push;
	t_node	*tmp;

	cost = INT_MAX;
	tmp = stack_a->head;
	while (tmp)
	{
		if (ft_abs(tmp->data->cost_a) < cost)
		{
			cost = tmp->data->cost_a;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_a, to_push);
	ft_prepare_stacks(stack_a, stack_b, tmp, ret);
	ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
}

/*int ft_bigga_chunk (t_stack *a, int *length)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		s_index;
	int		i;

	tmp = a->head;
	while (tmp)
	{
		i = 1;
		if (tmp->next)
			tmp2 = tmp->next;
		while (tmp2 && tmp->data->s_index + i == tmp2->data->s_index)
		{
			i++;
			tmp2 = tmp2->next;
		}
		if (i > *length)
		{
			s_index = tmp->data->s_index;
			*length = i;
		}
		tmp = tmp->next;
	}	
	return (s_index);
}*/

void 	ft_pushtill_3(t_stack *a, t_stack *b, t_list **ret)
{
	int	pushed;
	int i;

	pushed = 0;
	i = 0;
	while (a->max_size > 5 && i < a->max_size && pushed < a->max_size / 2)
	{
		if (a->head->data->s_index <= a->max_size / 2)
		{
			ft_lstadd_back(ret, ft_lstnew(ft_pb(a, b)));
			pushed++;
		}
		else
			ft_lstadd_back(ret, ft_lstnew(ft_ra(a)));
		i++;
	}
	while (a->size > 3)
		ft_lstadd_back(ret, ft_lstnew(ft_pb(a, b)));
}

void	ft_push_back(t_stack *stack_a, t_stack *stack_b, \
		int layered, t_list **ret)
{
	/*while (stack_a->head)
	{
		ft_pricing_to_b(stack_a);
		if (layered)
			ft_push_cheapest_layered(stack_a, stack_b, ret);
		else
			ft_push_cheapest(stack_a, stack_b, ret);
	}	
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));*/
	(void) layered;
	ft_pushtill_3(stack_a, stack_b, ret);
	ft_tiny_sort(stack_a, ret);
	while (stack_b->head)
	{
		ft_pricing_to_a(stack_a, stack_b);
		ft_pushback_cheapest(stack_a, stack_b, ret);
	}
}
