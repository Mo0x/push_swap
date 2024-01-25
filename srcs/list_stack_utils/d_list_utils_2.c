/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:10 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/25 18:22:03 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nodes(t_node *a, t_node *b)
{
	t_data	*tmp;
	int		index_a;
	int		index_b;

	index_a = a->data->index;
	index_b = b->data->index;
	tmp = malloc(sizeof(t_data));
	if (!tmp)
		exit(-1);
	ft_copy_data(a->data, tmp);
	free(a->data);
	a->data = b->data;
	b->data = tmp;
	a->data->index = index_a;
	b->data->index = index_b;
}

t_stack	*ft_stack_dup(t_stack *stack)
{
	t_stack	*ret;
	t_node	*iterator;
	t_node	*tmp;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->head = ft_node_new(stack->head->data->num);
	ret->size = 1;
	ft_copy_data(stack->head->data, ret->head->data);
	iterator = stack->head;
	iterator = iterator->next;
	while (iterator)
	{
		tmp = ft_node_new(stack->head->data->num);
		ft_copy_data(iterator->data, tmp->data);
		ft_node_add_back(&ret->head, tmp);
		ret->size += 1;
		iterator = iterator->next;
	}
	return (ret);
}

t_node	*ft_select_node(t_stack *stack, int index)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->data->index != index)
		tmp = tmp->next;
	return (tmp);
}

int	ft_give_value(t_stack *stack, int index)
{
	int	ret;

	ret = (ft_select_node(stack, index))->data->num;
	return (ret);
}

t_node	*ft_get_node(t_stack *stack, int value)
{
	t_node	*ret;

	ret = stack->head;
	while (ret)
	{
		if (ret->data->num == value)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}