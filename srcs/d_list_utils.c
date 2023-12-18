/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 13:52:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_dlst_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node *ft_dlst_first(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev; 
	return (lst);
}

void	ft_dlst_clear(t_node **lst)
{
	t_node	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		free(current->data);
		free(current);
	}
	lst = NULL;
}

t_node	*ft_dlst_new(int content)
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
	ret->data->layer = -1;
	ret->data->s_index = -1;
	return (ret);
}

void	ft_dlst_add_back(t_node **lst, t_node *new)
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
		last = ft_dlst_last(*lst);
		last->next = new;
		new->prev = last;
		new->data->index = new->prev->data->index + 1;
	}
}

void	ft_dlst_add_front(t_node **lst, t_node *new)
{
	t_node *first;
	
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		first = ft_dlst_first(*lst);
		first->prev = new;
		new->next = first;
	} 
}
/*t_node *ft_node_dup(t_node *node)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	ret->num = node->num;
	ret->index = node->index;
	ret->cost = node->cost;
	ret->layer = node->layer;
	ret->next = ;
	ret->prev = NULL;
	return (ret);
}*/

void	ft_copy_data(t_data *og, t_data *copy)
{
	copy->num = og->num;
	copy->index = og->index;
	copy->cost = og->cost;
	copy->layer = og->layer;
}

void	ft_swap_nodes(t_node *a, t_node *b)
{
	t_data *tmp;

	tmp = malloc(sizeof(t_data));
	if (!tmp)
		exit(-1);
	ft_copy_data(a->data, tmp);
	free(a->data);
	a->data = b->data;
	b->data = tmp;
}

t_stack	*stack_dup(t_stack *stack)
{
	t_stack	*ret;
	t_node	*iterator;
	t_node	*tmp;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->head = ft_dlst_new(stack->head->data->num);
	ret->size = 1;
	ft_copy_data(stack->head->data, ret->head->data);
	iterator = stack->head;
	while (iterator)
	{
		tmp = ft_dlst_new(stack->head->data->num);
		ft_copy_data(iterator->data, tmp->data);
		ft_dlst_add_back(&ret->head, tmp);
		ret->size + 1;
		iterator = iterator->next;
	}
	return (ret);
}