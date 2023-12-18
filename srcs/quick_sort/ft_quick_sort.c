/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:14:45 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 14:42:42 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_average(t_stack *stack)
{
	long long	sum;
	t_node		*tmp;
	long long	ret;

	sum = 0;
	tmp = stack->head;
	while (tmp)
	{
		sum += tmp->data->num;
		tmp = tmp->next;
	}
	ret = sum / stack->size;
	return (int)(ret);
}

int	ft_closest(int n, t_stack *stack)
{
	t_node	*tmp;
	int		score;
	int		best;
	int		ret;

	tmp = stack->head;
	score = ft_abs(tmp->data->num - n);
	best = score;
	while (tmp)
	{
		score = ft_abs(tmp->data->num - n);
		if (score < best)
		{
			best = score;
			ret = tmp->data->index;
		}
		tmp = tmp->next;
	}
	return (ret);
}*/

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
		pivot = partition(stack, low, high);
		ft_quick_sort(stack, low, pivot -1);
		ft_quick_sort(stack, pivot + 1, high);
	}
}
t_stack *ft_quick_sort_init(stack_a)
{
	t_stack	*ret;

	ret = ft_stack_dup(stack_a);
	ft_quick_sort(ret, 0, ret->size - 1);
	return (ret);
}

/* doc = https://www.programiz.com/dsa/quick-sort*/