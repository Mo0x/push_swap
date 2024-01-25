/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/25 17:39:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_closest(int *close_up, int *close_down, t_stack *stack_a, t_node *node)
{
	t_node	*a;

	a = stack_a->head;
	*close_up = INT_MAX;
	*close_down = -1;
	while (a)
	{
		if ((a->data->s_index > node->data->s_index) && (a->data->s_index < *close_up))
			*close_up = a->data->s_index;
		if ((a->data->s_index < node->data->s_index) && (a->data->s_index > *close_down))
			*close_down = a->data->s_index;
		a = a->next;
	}
	*close_up = ft_s_index_to_index(stack_a, *close_up);
	*close_down = ft_s_index_to_index(stack_a, *close_down);
}

void	ft_rotate_a(t_stack *stack_a, t_node *to_push)
{
	int		close_up;
	int		close_down;
	int		i;

	ft_closest(&close_up, &close_down, stack_a, to_push);
	ft_printf(2, "up : %d down : %d\n", close_up, close_down);
	if ((close_up == -1 && close_down == -1) || close_up == 0)
		return ;
	else if (close_up != -1)
	{
		if (close_up > (stack_a->size / 2))
		{
			i = close_up - ((stack_a->size / 2));
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
		if (close_down > (stack_a->size / 2))
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