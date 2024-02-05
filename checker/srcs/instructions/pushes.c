/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:45 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 15:44:22 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*copy;

	if (!(stack_b->head))
		return (NULL);
	copy = ft_node_dup(stack_b->head);
	ft_node_add_front(stack_a, copy);
	ft_node_del(stack_b, stack_b->head);
	stack_a->tail = ft_node_last(stack_a->head);
	if (!(stack_a->size))
		stack_a->size = 1;
	else
		stack_a->size++;
	if (!(stack_b->size))
		stack_b->size = 0;
	else
		stack_b->size--;
	return ("pa");
}

char	*ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*copy;

	if (!(stack_a->head))
		return (NULL);
	copy = ft_node_dup(stack_a->head);
	ft_node_add_front(stack_b, copy);
	ft_node_del(stack_a, stack_a->head);
	stack_b->tail = ft_node_last(stack_b->head);
	if (!(stack_b->size))
		stack_b->size = 1;
	else
		stack_b->size++;
	if (!(stack_a->size))
		stack_a->size = 0;
	else
		stack_a->size--;
	return ("pb");
}