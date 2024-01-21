/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:11:51 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/21 18:46:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_baby_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	}
}

t_node	*biggest_node(t_stack *stack)
{
	int		bigger;
	t_node	*tmp;
	t_node	*ret;

	if (stack == NULL)
		return (NULL);
	tmp = stack->head;
	bigger = INT_MIN;
	while (tmp)
	{
		if (tmp->data->num > bigger)
		{	
			bigger = tmp->data->num;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_tiny_sort(t_stack *stack_a)
{
	t_node	*bigger;

	bigger = biggest_node(stack_a);
	if (stack_a->head == bigger)
		ft_putendl_fd(ft_ra(stack_a), 1);
	else if (stack_a->head->next == bigger)
		ft_putendl_fd(ft_rra(stack_a), 1);
	if (stack_a->head->data->num > \
	stack_a->head->next->data->num)
		ft_putendl_fd(ft_sa(stack_a), 1);
}