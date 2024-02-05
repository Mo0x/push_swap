/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:22:17 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/26 17:26:55 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	node = node->next;
	while (node)
	{
		if (node->data->num < node->prev->data->num)
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_s_index_to_index(t_stack *stack, int s_index)
{
	t_node	*tmp;

	tmp = stack->head;
	if (s_index == INT_MAX)
		return (-1);
	while (tmp)
	{
		if (tmp->data->s_index == s_index)
			return (tmp->data->index);
		tmp = tmp->next;
	}
	return (-1);
}