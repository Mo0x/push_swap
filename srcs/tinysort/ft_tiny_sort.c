/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:11:51 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/21 18:11:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_baby_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf(1, "Im baby");
	(void)stack_a;
	(void)stack_b;
}

t_node *biggest_node(t_stack *stack)
{
	int		bigger;
	t_node	*tmp;
	t_node	*ret;

	if (stack == NULL)
		return (NULL);
	tmp = stack->head;
	highest = INT_MIN;
	while (tmp)
	{
		if (tmp->data->num > bigger)
			ret = tmp;
		tmp = tmp->next;
	}
}

void	ft_tiny_sort(t_stack *stack_a)
{
	t_node	*bigger;

	bigger = biggest_node(stack_a);
	if (stack_a->head == bigger)
		ft_putendl_fd(ft_ra(stack_a), 1);
	else if (stack_a->head->next == bigger)
		ft_putendl_fd(ft_rra(stack_a), 1);
	if(stack_a->head->data->num > stack_a->head->next->data->num)
		ft_putendl_fd(ft_sa(stack_a), 1);
	}