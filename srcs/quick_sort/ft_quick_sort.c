/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:14:45 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/19 15:32:39 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_stack *stack_to_index, t_stack *ref)
{
	t_node	*tmp;
	t_node	*index;

	tmp = stack_to_index->head;
	while (tmp)
	{
		index = ft_get_node(ref, tmp->data->num);
		tmp->data->s_index = index->data->index;
		tmp = tmp->next;
	}
}

int		ft_partition(t_stack *stack, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	pivot = ft_give_value(stack, high);
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (ft_give_value(stack, j) <= pivot)
		{
			i++;
			ft_swap_nodes(ft_select_node(stack, i), ft_select_node(stack, j));
		}
		j++;
	}
	ft_swap_nodes(ft_select_node(stack, i + 1), ft_select_node(stack, high));
	return (i + 1);
}

void	ft_quick_sort(t_stack *stack, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_partition(stack, low, high);
		ft_quick_sort(stack, low, pivot -1);
		ft_quick_sort(stack, pivot + 1, high);
	}
}
t_stack *ft_quick_sort_init(t_stack *stack_a)
{
	t_stack	*ret;

	ret = ft_stack_dup(stack_a);
	ft_quick_sort(ret, 0, ret->size - 1);
	return (ret);
}
