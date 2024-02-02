/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:31 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/02 19:25:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// here he turn in the wrong sense
void	ft_rotate_a(t_stack *stack_a, t_node *to_push, t_list **ret)
{
	int	up;
	int	down;
	int	i;

	ft_closest(&up, &down, stack_a, to_push->data->s_index);
	if ((up == -1 && down == -1) || (up == 0 && down == -1) || \
		(down == (stack_a->size - 1) && up == -1))
		return ;
	else if (up != -1)
	{
		if (up > (stack_a->size / 2) + 1)
		{
			i = stack_a->size - up;
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
		}
		else
		{
			i = up;
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_ra(stack_a)));
		}
	}
	else if (down != -1)
	{
		if (down > (stack_a->size / 2))
		{
			i = stack_a->size - (down + 1);
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
		}
		else
		{
			i = down + 1;
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_ra(stack_a)));
		}
	}
}

void	ft_pricing_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;
	int		close_up;
	int		close_down;

	b = stack_b->head;
	ft_pricing_to_b(stack_b);
	while (b)
	{
		ft_closest(&close_up, &close_down, stack_a, b->data->s_index);
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

void	ft_pushback_node(t_stack *stack_a, t_stack *stack_b, t_node *to_push, t_list **ret)
{
	int	i;

	ft_rotate_a(stack_a, to_push, ret);
	if (to_push->data->index == 0)
		ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	else if (to_push->data->index == 1)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rb(stack_b)));
		ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	}
	else if (to_push->data->index == stack_b->size - 1)
	{
		ft_lstadd_back(ret, ft_lstnew(ft_rrb(stack_b)));
		ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	}
	else
	{
		if (to_push->data->index < (stack_b->size / 2) + 1)
		{
			i = to_push->data->index;
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_rb(stack_b)));
		}
		else
		{
			i = (stack_b->size - to_push->data->index);
			while (i-- > 0)
				ft_lstadd_back(ret, ft_lstnew(ft_rrb(stack_b)));
		}
		ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	}
}


void	ft_pushback_cheapest(t_stack *stack_a, t_stack *stack_b, t_list **ret)
{
	int		cost;
	t_node	*tmp;
	int		to_push;
	int		layer;

	layer = ft_highest_layer(stack_b);
	cost = INT_MAX;
	tmp = stack_b->head;
	while (tmp)
	{
		if (tmp->data->cost < cost && layer == tmp->data->layer)
		{
			cost = tmp->data->cost;
			to_push = tmp->data->index;
		}
		tmp = tmp->next;
	}
	tmp = ft_select_node(stack_b, to_push);


	ft_printf(2, "selected === i %d     cost %d\n\n", tmp->data->index, tmp->data->cost);
	/*t_node *deb = stack_a->head;
	while (deb)
	{
		ft_printf(2, "stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", deb->data->index,deb->data->s_index, deb->data->num, deb->data->layer, deb->data->cost);
		deb = deb->next;
	}*/
	t_node *deb2 = stack_b->head;
	while (deb2)
	{
		ft_printf(2, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", deb2->data->index,deb2->data->s_index, deb2->data->num, deb2->data->layer, deb2->data->cost);
		deb2 = deb2->next;
	}





	ft_pushback_node(stack_a, stack_b, tmp, ret);
}