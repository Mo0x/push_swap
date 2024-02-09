/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/09 15:37:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_closest(int *close_up, int *close_down, t_stack *stack_a, int node_s)
{
	t_node	*a;
	int		s_index;

	a = stack_a->head;
	*close_up = INT_MAX;
	*close_down = -1;
	while (a)
	{
		s_index = a->data->s_index;
		if ((s_index > node_s) && (s_index < *close_up))
			*close_up = s_index;
		if ((s_index < node_s) && (s_index > *close_down))
			*close_down = s_index;
		a = a->next;
	}
	*close_up = ft_s_index_to_index(stack_a, *close_up);
	*close_down = ft_s_index_to_index(stack_a, *close_down);
}*/

int	ft_set_pos(t_stack *a, int s_index, int max, int pos)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->data->s_index > s_index && tmp->data->s_index < max)
		{
			max = tmp->data->s_index;
			pos = tmp->data->index;
		}
		tmp = tmp->next;
	}
	if (max != INT_MAX)
		return (pos);
	tmp = a->head;
	while (tmp)
	{
		if (tmp->data->s_index < max)
		{
			max = tmp->data->s_index;
			pos = tmp->data->index;
		}
		tmp = tmp->next;
	}
	return (pos);
}

/*void	ft_prepare_b(t_stack *stack)
{
	t_node	*node;
	int		pos;

	node = stack->head;
	while (node)
	{
		if (node->data->index > (stack->size / 2) + 1)
			node->data->cost_b = (stack->size - node->data->index) * -1;
		else
			node->data->cost_b = node->data->index;
		node = node->next;
	}
}*/

void	ft_pricing_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	int		pos;

	b = stack_b->head;
	pos= 0;
	while (b)
	{
		pos = ft_set_pos(stack_a, b->data->s_index, INT_MAX, pos);
		b->data->cost_b = b->data->index;
		if (b->data->index > stack_b->size / 2)
			b->data->cost_b = (stack_b->size - b->data->index) * -1; 
		b->data->cost_a = pos;
		if (pos > stack_a->size / 2)
			b->data->cost_a = (stack_a->size - pos) * -1;
		b = b->next;
	}
}

/*void	ft_pricing_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	int		up;
	int		down;

	b = stack_b->head;
	ft_prepare_b(stack_b);
	while (b)
	{
		ft_closest(&up, &down, stack_a, b->data->s_index);
		if (up != -1)
		{
			if (up > (stack_a->size / 2) + 1)
				b->data->cost_a = 	up - stack_a->size;
			else
				b->data->cost_a = up;
		}
		else if (down != -1)
		{
			if (down > (stack_a->size / 2) + 1)
				b->data->cost_a = (stack_a->size - down -1) * -1;
			else
				b->data->cost_a = (down + 1);
		}
		b = b->next;
	}
}*/

void	ft_pushback_cheapest(t_stack *stack_a, t_stack *stack_b, t_list **ret)
{
	int		cost;
	t_node	*tmp;
	int		to_push;
	int		layer;

	layer = ft_highest_layer(stack_b);
	cost = INT_MAX;
	tmp = stack_b->head;
	(void) layer;
	while (tmp)
	{
		if (ft_abs(tmp->data->cost_a) + ft_abs(tmp->data->cost_b) \
			< ft_abs(cost) && layer == tmp->data->layer)
		{
			cost = ft_abs(tmp->data->cost_a) + ft_abs(tmp->data->cost_b);
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_b, to_push);
	ft_prepare_stacks(stack_a, stack_b, tmp, ret);
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
}

/*void	ft_pushback_cheapest(t_stack *a, t_stack *b, t_list **ret)
{
	int	cost;
	t_node	*tmp;

	tmp = stack_b->head;
	cost = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->data->cost_a) + ft_abs(tmp->data->cost_b) <  ft_abs(cheapesty))
	}
}*/

/*static int	ft_cost(t_node *tmp)
{
	int	sum;
	int	a;
	int	b                        ;

	a = tmp->data->cost_a;
	b = tmp->data->cost_b;
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (a >= b)
			sum = a;
		else
			sum = b;
	}
	else
		sum = ft_abs(a) + ft_abs(b);
	return (sum);
}

void	ft_pushback_cheapest(t_stack *stack_a, t_stack *stack_b, t_list **ret)
{
	int		cost;
	int		sum;
	t_node	*tmp;
	int		to_push;
	int		layer;

	layer = ft_highest_layer(stack_b);
	cost = INT_MAX;
	tmp = stack_b->head;
	(void)layer;
	while (tmp)
	{
		sum = ft_cost(tmp);
		if (sum < cost && layer == tmp->data->layer)
		{
			cost = sum;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_b, to_push);
	ft_prepare_stacks(stack_a, stack_b, tmp, ret);
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
}*/