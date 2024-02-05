/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:23:17 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/02 15:34:15 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_sa(t_stack *stack)
{
	if (stack->size < 2)
		return ("sa");
	ft_swap_nodes(ft_select_node(stack, 0), ft_select_node(stack, 1));
	return ("sa");
}

char	*ft_sb(t_stack *stack)
{
	ft_sa(stack);
	return("sb");
}

char	*ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sa(stack_b);
	return ("ss");
}