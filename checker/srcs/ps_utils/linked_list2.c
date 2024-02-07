/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:01:35 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/07 15:35:18 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_fix_index(t_node *to_fix)
{
	while (to_fix)
	{
		to_fix->data->index -= 1;
		to_fix = to_fix->next;
	}
}

void	ft_nodes_clear(t_node **lst)
{
	t_node	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		free(current->data);
		free(current);
	}
	lst = NULL;
}
