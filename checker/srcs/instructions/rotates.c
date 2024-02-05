/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:09:44 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 15:44:42 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_ra(t_stack *stack_a)
{
	t_node	*tmp;

	if (stack_a->size < 2)
		return ("ra");
	if (stack_a->head && stack_a->head->next)
	{
		tmp = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_a->head->prev = NULL;
		stack_a->tail->next = tmp;
		tmp->prev = stack_a->tail;
		tmp->next = NULL;
		stack_a->tail = tmp;
		stack_a->head->data->index = 0;
		tmp = stack_a->head->next;
		while (tmp)
		{
			tmp->data->index = tmp->prev->data->index + 1;
			tmp = tmp->next;
		}
	}
	return ("ra");
}

char	*ft_rb(t_stack *stack_b)
{
	ft_ra(stack_b);
	return ("rb");
}

char	*ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	return ("rr");
}