/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:03:35 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/07 15:33:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*ft_node_dup(t_node *node)
{
	t_node	*ret;
	t_data	*data;

	ret = malloc(sizeof(t_node));
	if (!ret)
		ft_eq("Error malloc");
	data = malloc(sizeof(t_data));
	if (!data)
		ft_eq("Error malloc");
	ft_copy_data(node->data, data);
	ret->next = NULL;
	ret->prev = NULL;
	ret->data = data;
	return (ret);
}

void	ft_copy_data(t_data *og, t_data *copy)
{
	copy->num = og->num;
	copy->index = og->index;
	copy->cost_a = og->cost_a;
	copy->cost_b = og->cost_b;
	copy->layer = og->layer;
	copy->s_index = og->s_index;
}

t_node	*ft_select_node(t_stack *stack, int index)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->data->index != index)
		tmp = tmp->next;
	return (tmp);
}

t_node	*ft_node_new(int content)
{
	t_node	*ret;
	t_data	*data;

	ret = malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;
	ret->data->num = content;
	ret->data->index = 0;
	ret->data->cost_a = 0;
	ret->data->cost_b = 0;
	ret->data->layer = 0;
	ret->data->s_index = -1;
	return (ret);
}

void	ft_node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		new->data->index = 0;
	}
	else
	{
		last = ft_node_last(*lst);
		last->next = new;
		new->prev = last;
		new->data->index = new->prev->data->index + 1;
	}
}
