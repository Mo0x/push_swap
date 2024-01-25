/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:17:28 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/25 18:19:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ret->data->cost = -1;
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

void	ft_node_add_front(t_stack *lst, t_node *new)
{
	t_node	*first;
	t_node	*fixer;

	if (!new)
		return ;
	if (!(lst->head))
	{
		lst->head = new;
		new->data->index = 0;
	}
	else
	{
		first = ft_node_first(lst->head);
		first->prev = new;
		new->next = first;
		new->data->index = 0;
		fixer = new->next;
		while (fixer)
		{
			fixer->data->index += 1;
			fixer = fixer->next;
		}
		lst->head = new;
	}
}

void	ft_copy_data(t_data *og, t_data *copy)
{
	copy->num = og->num;
	copy->index = og->index;
	copy->cost = og->cost;
	copy->layer = og->layer;
	copy->s_index = og->s_index;
}

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