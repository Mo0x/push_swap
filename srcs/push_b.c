/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/23 18:43:59 by mgovinda         ###   ########.fr       */
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
/* add or remove the  + 1*/

/*void	ft_pricing_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	t_node	*a;
	int		close_up;
	int		close_down;

	b = stack_b->head;
	ft_pricing_to_b(stack_b);
	while (b)
	{
		a = stack_a->head;
		close_up = stack_a->size + 1;
		close_down = -1;
		while (a)
		{
			if ((a->data->s_index > b->data->s_index) && (a->data->s_index < close_up))
				close_up = a->data->s_index;
			if ((a->data->s_index < b->data->s_index) && (a->data->s_index < close_up))
				close_down = a->data->s_index;
			a = a->next;
		}
		close_up = ft_s_index_to_index(stack_a, close_up);
		close_down = ft_s_index_to_index(stack_a, close_down);
		if (close_up != -1)
		{
			if (close_up > (stack_a->size / 2) + 1)
				b->data->cost += close_up - (stack_a->size / 2);
			else
				b->data->cost += close_up;
		}
		else if (close_down != -1)
		{
			if (close_down > (stack_a->size / 2) + 1)
				b->data->cost += (stack_a->size - close_down);
			else
				b->data->cost += (close_down + 1);
		}
		b = b->next;
	}
}*/

/*void	ft_closest(int *close_up, int *close_down, t_stack *stack_a, t_node *node)
{
	t_node	*a;

	a = stack_a->head;
	*close_up = stack_a->size + 1;
	*close_down = -1;
	while (a)
	{
		if ((a->data->s_index > node->data->s_index) && (a->data->s_index < *close_up))
			*close_up = a->data->s_index;
		if ((a->data->s_index < node->data->s_index) && (a->data->s_index < *close_up))
			*close_down = a->data->s_index;
		a = a->next;
	}
}*/

/* for push node perhaps stock the return into a variable then optimize the path
	also to gain line, put the push at the end and do not repeat it every time :)*/
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

/*void	ft_rotate_a(t_stack *stack_a, t_node *to_push)
{
	int		close_up;
	int		close_down;
	int		i;

	ft_closest(&close_up, &close_down, stack_a, to_push);
	if (close_up != -1)
	{
		if (close_up > (stack_a->size / 2) + 1)
		{
			i = close_up - (stack_a->size / 2);
			while (i-- > 0)
				ft_putendl_fd(ft_rra(stack_a), 1);
		}
		else
		{
			i = close_up;
			while (i-- > 0)
				ft_putendl_fd(ft_ra(stack_a), 1);
		}
	}
	else if (close_down != -1)
	{
		if (close_down > (stack_a->size / 2) + 1)
		{
			i = stack_a->size - close_down;
			while (i-- > 0)
				ft_putendl_fd(ft_rra(stack_a), 1);
		}
		else
		{
			i = close_down + 1;
			while (i-- > 0)
				ft_putendl_fd(ft_ra(stack_a), 1);
		}
	}
}

void	ft_pushback_node(t_stack *stack_a, t_stack *stack_b, t_node *to_push)
{
	int	i;

	ft_rotate_a(stack_a, to_push);
	if (to_push->data->index == 0)
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	else if (to_push->data->index == 1)
	{
		ft_putendl_fd(ft_sb(stack_b), 1);
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	}
	else if (to_push->data->index == stack_a->size - 1)
	{
		ft_putendl_fd(ft_rrb(stack_a), 1);
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	}
	else
	{
		if (to_push->data->index < (stack_a->size / 2) + 1)
		{
			i = to_push->data->index;
			while (i-- > 0)
				ft_putendl_fd(ft_rb(stack_b), 1);
		}
		else
		{
			i = (stack_a->size - to_push->data->index);
			while (i-- > 0)
				ft_putendl_fd(ft_rrb(stack_b), 1);
		}
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	}
}*/

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

/* put cheapest node to on top of b, put close up on top of a, close down bottom of a then push the node from b to a*/
/*void	ft_pushback_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	t_node	*tmp;
	int		to_push;

	cost = 2147483647;
	tmp = stack_b->head;
	while (tmp)
	{
		if (tmp->data->cost < cost)
		{
			cost = tmp->data->cost;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_b, to_push);
	ft_pushback_node(stack_a, stack_b, tmp);
}*/

void	ft_push_back(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->head)
	{
		ft_pricing_to_b(stack_a);
		ft_push_cheapest(stack_a, stack_b);
	}
	ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	ft_tiny_sort(stack_a);
	ft_pricing_to_a(stack_a, stack_b);
	ft_pushback_cheapest(stack_a, stack_b);
	ft_pricing_to_a(stack_a, stack_b);
	ft_pushback_cheapest(stack_a, stack_b);
	ft_pricing_to_a(stack_a, stack_b);
	/*ft_pushback_cheapest(stack_a, stack_b);
	ft_pricing_to_a(stack_a, stack_b);
	ft_pushback_cheapest(stack_a, stack_b);
	ft_pricing_to_a(stack_a, stack_b);*/
	/*while (stack_b->head)
	{
		ft_pricing_to_a(stack_a, stack_b);
		ft_pushback_cheapest(stack_a, stack_b);
	}*/
}
