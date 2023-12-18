/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:35:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 13:34:50 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bigboi_sort(t_stack *stack_a)
{
	t_stack	*secret_stack;
	t_stack	*stack_b;

	secret_stack = ft_quick_sort_init(stack_a);
	if (!secret_stack)
		exit(1);
	ft_indexing(stack_a, secret_stack);
	ft_layering(stack_a, stack_b);
	ft_push_back(stack_a, stack_b);
}

void	ft_push_swap(t_stack *stack_a)
{
	if (stack_a->size == 3)
		ft_tiny_sort(stack_a);
	else if (stack_a->size == 5)
		ft_baby_sort(stack_a);
	else
		ft_bigboi_sort(stack_a);
}