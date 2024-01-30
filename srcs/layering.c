/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:33 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/30 19:08:09 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
*/
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

/*int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}*/

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

int	ft_determine_layers(t_stack *stack)
{
	if (stack->max_size > 499)
		return (4);
	else if (stack->max_size > 299)
		return (3);
	else if (stack->max_size > 99)
		return (2);
	else
		return (0);
}

void	ft_layering(int layers, t_stack *stack)
{
	float	small;
	float	big;
	int		i;
	t_node	*tmp;

	ft_printf(2, "%d = layer\n", layers);
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

/*void	ft_layering(int layers, t_stack *stack)
{
	float	a;
	float	b;
	float	c;
	t_node	*tmp;

	tmp = stack->head;
	a = stack->size * 0.25;
	b = stack->size * 0.5;
	c = stack->size * 0.75;
	while (tmp)
	{
		if (layers == 2)
		{
			if (tmp->data->s_index < b)
				tmp->data->layer = 1;
			else
				tmp->data->layer = 2;
		}
		if (layers == 4)
		{
			if (tmp->data->s_index > c)
				tmp->data->layer = 4;
			else if (tmp->data->s_index > b)
				tmp->data->layer = 3;
			else if (tmp->data->s_index > a)
				tmp->data->layer = 2;
			else
				tmp->data->layer = 1;
		}
		tmp = tmp->next;
	}
}*/

int	ft_layering_init(t_stack *stack)
{
	int	layers_num;

	layers_num = ft_determine_layers(stack);
	if (layers_num)
		ft_layering(layers_num, stack);
	return (1);
}