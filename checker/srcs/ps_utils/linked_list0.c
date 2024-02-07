/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:59:53 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/07 15:34:16 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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

void	ft_node_add_front(t_stack *lst, t_node *new)
{
	t_node	*first;
	t_node	*fixer;

	if (!new)
		return ;
	if (!(lst->head))
	{
		lst->head = new;
		new->data->index = 0;
	}
	else
	{
		first = ft_node_first(lst->head);
		first->prev = new;
		new->next = first;
		new->data->index = 0;
		fixer = new->next;
		while (fixer)
		{
			fixer->data->index += 1;
			fixer = fixer->next;
		}
		lst->head = new;
	}
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

void	ft_swap_nodes(t_node *a, t_node *b)
{
	t_data	*tmp;
	int		index_a;
	int		index_b;

	index_a = a->data->index;
	index_b = b->data->index;
	tmp = malloc(sizeof(t_data));
	if (!tmp)
		exit(-1);
	ft_copy_data(a->data, tmp);
	free(a->data);
	a->data = b->data;
	b->data = tmp;
	a->data->index = index_a;
	b->data->index = index_b;
}
