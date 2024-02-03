/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/03 16:30:51 by mgovinda         ###   ########.fr       */
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
	/*if (layer % 2)
		ft_lstadd_back(ret, ft_lstnew(ft_rb(stack_b)));*/
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

void	ft_push_back(t_stack *stack_a, t_stack *stack_b, \
		int layered, t_list **ret)
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
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = a=%d b=%d\n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost_a, tmp->data->cost_b);
		tmp = tmp->next;
	}
	t_node *tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = a=%d b=%d\n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost_a, tmp2->data->cost_b);
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
		/*t_node *tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(2, "stack a i = %d, s_i = %d :%d, layer = %d cost = a=%d b=%d\n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost_a, tmp->data->cost_b);
		tmp = tmp->next;
	}
	t_node *tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(2, "stack b i = %d, s_i = %d :%d, layer = %d cost = a=%d b=%d\n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost_a, tmp2->data->cost_b);
		tmp2 = tmp2->next;
	}
	ft_printf(2,"\n NEXT\n ");*/
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
