/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:09:44 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/19 16:23:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_ra(t_stack *stack_a)
{
	t_node *tmp;

	tmp = stack_a->head;
	stack_a->head = tmp->next;
	tmp->next->prev = NULL;
	stack_a->tail->next = tmp;
	tmp->prev = stack_a->tail;
	tmp->next = NULL;
	stack_a->tail = tmp;
	stack_a->head->data->index = 0;
	tmp = stack_a->head->next;
	while (tmp)
	{
		tmp->data->index += 1;
		tmp = tmp->next;
	}
	return ("ra");
}