/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:35:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/17 19:52:01 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a)
{
	if (stack_a->size == 3)
		ft_tiny_sort(stack_a);
	else if (stack_a->size == 5)
		ft_baby_sort(stack_a);
	else
		ft_bigboi_sort(stack_a);
}