/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:42:04 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/02 15:33:17 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rra(t_stack *stack)
{
	t_node	*tmp;
	if (stack->size < 2)
		return ("rra");
	if (stack->head)
	{
		tmp = stack->tail;
		stack->tail = tmp->prev;
		tmp->prev->next = NULL;
		stack->head->prev = tmp;
		tmp->prev = NULL;
		tmp->next = stack->head;
		stack->head = tmp;
		tmp->data->index = 0;
		tmp = tmp->next;
		while (tmp)
		{
			tmp->data->index = tmp->prev->data->index + 1;
			tmp = tmp->next;
		}
	}
	return ("rra");
}

char	*ft_rrb(t_stack *stack)
{
	ft_rra(stack);
	return ("rrb");
}

char	*ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rra(stack_b);
	return ("rrr");
}