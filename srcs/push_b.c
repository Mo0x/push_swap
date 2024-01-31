/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/31 17:13:18 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pricing_to_b(t_stack *stack)
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
}

void	ft_push_node(t_stack *stack_a, t_stack *stack_b, t_node *to_push, t_list **ret)
{
	int	i;

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
	{
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
}

void	ft_push_cheapest_layered(t_stack *stack_a, t_stack *stack_b, t_list **ret)
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
	ft_push_node(stack_a, stack_b, tmp, ret);
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
		if (tmp->data->cost < cost)
		{
			cost = tmp->data->cost;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_a, to_push);
	ft_push_node(stack_a, stack_b, tmp, ret);
}

void	ft_push_back(t_stack *stack_a, t_stack *stack_b, int layered, t_list **ret)
{
	while (stack_a->head)
	{
		ft_pricing_to_b(stack_a);
		if (layered)
			ft_push_cheapest_layered(stack_a, stack_b, ret);
		else
			ft_push_cheapest(stack_a, stack_b, ret);
	}	
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	ft_tiny_sort(stack_a, ret);
	/*ft_pricing_to_a(stack_a, stack_b);
	t_node *tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost);
		tmp = tmp->next;
	}
	t_node *tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(1, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost);
		tmp2 = tmp2->next;
	}
	ft_pushback_cheapest(stack_a, stack_b);
	tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost);
		tmp = tmp->next;
	}
	tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(1, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost);
		tmp2 = tmp2->next;
	}
	sleep(10);*/
	while (stack_b->head)
	{
		ft_pricing_to_a(stack_a, stack_b);
		ft_pushback_cheapest(stack_a, stack_b, ret);
		/*t_node 	*tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost);
		tmp = tmp->next;
	}
	t_node *tmp2 = stack_b->head;
	ft_printf(1, "=================\n");
	while (tmp2)
	{
		ft_printf(1, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost);
		tmp2 = tmp2->next;
	}*/
	}
}
