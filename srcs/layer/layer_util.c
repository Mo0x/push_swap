/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:07 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/02 16:31:46 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_highest_layer(t_stack *stack)
{
	t_node	*tmp;
	int		layer;

	tmp = stack->head;
	layer = 0;
	while (tmp)
	{
		if (tmp->data->layer > layer)
			layer = tmp->data->layer;
		tmp = tmp->next;
	}
	return (layer);
}

int	ft_lowest_layer(t_stack *stack)
{
	t_node	*tmp;
	int		layer;

	tmp = stack->head;
	layer = 99;
	while (tmp)
	{
		if (tmp->data->layer < layer)
			layer = tmp->data->layer;
		tmp = tmp->next;
	}
	return (layer);
}