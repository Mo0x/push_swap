/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:22:17 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/07 16:55:18 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_lowest_s(t_stack *a)
{
	t_node	*tmp;
	int ret;

	ret = INT_MAX;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->data->s_index < ret)
			ret = tmp->data->s_index;
		tmp = tmp->next;
	}
	return (ret);
}

int ft_highest_s(t_stack *a)
{
	t_node	*tmp;
	int		ret;

	ret = INT_MIN;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->data->s_index > ret)
			ret = tmp->data->s_index;
		tmp = tmp->next; 
	}
	return (ret);
}
