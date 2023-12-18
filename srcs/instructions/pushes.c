/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:45 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 17:39:09 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*copy;

	if (!(stack_b->head))
		return (NULL);
	copy = ft_node_dup(stack_b->head);
	ft_node_add_front(stack_a, copy);
	ft_node_del(stack_b, stack_b->head);
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
	return ("pb");
}