/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:33 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/20 17:32:37 by mgovinda         ###   ########.fr       */
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

int	ft_determine_layers(t_stack *stack)
{
	if (stack->size > 499)
		return (4);
	else if (stack->size > 99)
		return (2);
	else
		return (0);
}

void	ft_layering_init(t_stack *stack)
{
	int	layers_num;

	layers_num = ft_determine_layers(stack);
}