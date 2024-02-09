/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:33 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/09 15:30:36 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ((int)ret);
}

/* best for 500 so far 2 uncoined pb cheapest no rr rrr ?!
	best for 100 0 unmcoined pb cheapest no rr rrr*/

int	ft_determine_layers(t_stack *stack)
{
	if (stack->max_size > 499)
		return (0);
	else if (stack->max_size > 299)
		return (2);
	else if (stack->max_size > 99)
		return (0);
	else if (stack->max_size > 10)
		return (0);
	else
		return (0);
}

void	ft_layering(int layers, t_stack *stack)
{
	float	small;
	float	big;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	small = stack->max_size / layers;
	while (tmp)
	{
		i = layers - 1;
		while (i > 0)
		{
			big = small * i;
			if (tmp->data->s_index > big && tmp->data->layer < i + 1)
				tmp->data->layer = i + 1;
			i--;
		}
		if (tmp->data->layer == 0)
			tmp->data->layer = 1;
		tmp = tmp->next;
	}
}

int	ft_layering_init(t_stack *stack)
{
	int	layers_num;

	layers_num = ft_determine_layers(stack);
	if (layers_num)
		ft_layering(layers_num, stack);
	return (1);
}