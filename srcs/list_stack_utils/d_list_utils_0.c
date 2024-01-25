/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:15:01 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/25 18:29:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fix_index(t_node *to_fix)
{
	while (to_fix)
	{
		to_fix->data->index -= 1;
		to_fix = to_fix->next;
	}
}

void	ft_node_del(t_stack *stack, t_node *to_del)
{
	if (!to_del || !(stack->head))
		return ;
	if (stack->head == to_del)
	{
		stack->head = to_del->next;
		if (to_del->next)
			to_del->next->prev = NULL;
	}
	if (to_del->next != NULL)
	{
		to_del->next->prev = to_del->prev;
		ft_fix_index(to_del->next);
	}
	if (to_del->prev != NULL)
		to_del->prev->next = to_del->next;
	free(to_del->data);
	free(to_del);
}

t_node	*ft_node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_node_first(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
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

