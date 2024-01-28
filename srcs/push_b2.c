/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/28 20:35:33 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_closest(int *close_up, int *close_down, t_stack *stack_a, int node_s)
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
}

void	ft_rotate_a(t_stack *stack_a, t_node *to_push)
{
	int	up;
	int	down;
	int	i;

	ft_closest(&up, &down, stack_a, to_push->data->s_index);
	if ((up == -1 && down == -1) || (up == 0 && down == -1))
		return ;
	else if (up != -1)
	{
		if (up > (stack_a->size / 2))
		{
			i = stack_a->size - up;
			while (i-- > 0)
				ft_putendl_fd(ft_rra(stack_a), 1);
		}
		else
		{
			i = up;
			while (i-- > 0)
				ft_putendl_fd(ft_ra(stack_a), 1);
		}
	}
	else if (down != -1)
	{
		if (down > (stack_a->size / 2))
		{
			i = stack_a->size - (down + 1);
			while (i-- > 0)
				ft_putendl_fd(ft_rra(stack_a), 1);
		}
		else
		{
			i = down + 1;
			while (i-- > 0)
				ft_putendl_fd(ft_ra(stack_a), 1);
		}
	}
}

void	ft_pricing_to_a(t_stack *stack_a, t_stack *stack_b)
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
		close_up = INT_MAX;
		close_down = -1;
		while (a)
		{
			if ((a->data->s_index > b->data->s_index) && (a->data->s_index < close_up))
				close_up = a->data->s_index;
			if ((a->data->s_index < b->data->s_index) && (a->data->s_index > close_down))
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
	else if (to_push->data->index == stack_b->size - 1) //perhaps wrong
	{
		ft_putendl_fd(ft_rrb(stack_b), 1);
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	}
	else
	{
		if (to_push->data->index < (stack_b->size / 2) + 1)
		{
			i = to_push->data->index;
			while (i-- > 0)
				ft_putendl_fd(ft_rb(stack_b), 1);
		}
		else
		{
			i = (stack_b->size - to_push->data->index);
			while (i-- > 0)
				ft_putendl_fd(ft_rrb(stack_b), 1);
		}
		ft_putendl_fd(ft_pa(stack_a, stack_b), 1);
	}
}


void	ft_pushback_cheapest(t_stack *stack_a, t_stack *stack_b)
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
}