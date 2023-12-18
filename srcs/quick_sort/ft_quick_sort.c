/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:14:45 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 13:38:14 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
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
}

void	ft_quick_sort(t_stack *stack, int low, int high)
{
	int	pivot;
	t_stack	secret_stack;

	pivot = ft_average(stack_a);
	i = 0;
	pivot = i + 0;
	(void)pivot;
}
t_stack *ft_quick_sort_init(stack_a)
{
	t_stack	*ret;

	ret = ft_stack_dup(stack_a);
	ft_quick_sort(ret, 0, ret->size - 1);
	return (ret);
}

/* doc = https://www.programiz.com/dsa/quick-sort*/