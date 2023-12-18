/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 17:36:35 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fix_index(t_node *to_fix)
{
	while (to_fix)
	{
		to_fix->data->index -= 1;
		to_fix = to_fix->next; 
	}
}

void	ft_node_del(t_stack *stack, t_node *to_del)
{
	if (!to_del || !(stack->head))
		return ;
	if (stack->head == to_del)
	{
		stack->head = to_del->next;
		to_del->next->prev = NULL;
	}
	if (to_del->next != NULL)
	{
		to_del->next->prev = to_del->prev;
		ft_fix_index(to_del->next);
	}
	if (to_del->prev != NULL)
		to_del->prev->next = to_del->next;
	free(to_del->data);
	free(to_del);
}

t_node	*ft_node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node *ft_node_first(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev; 
	return (lst);
}

void	ft_nodes_clear(t_node **lst)
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
	ret->data->layer = -1;
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
	t_node *first;
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
}

t_node *ft_node_dup(t_node *node)
{
	t_node	*ret;
	t_data	*data;

	ret = malloc(sizeof(t_node));
	if (!ret)
		ft_eq("Error malloc");
	data = malloc(sizeof(t_data));
	if (!ret)
		ft_eq("Error malloc");
	ft_copy_data(node->data, data);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}



void	ft_swap_nodes(t_node *a, t_node *b)
{
	t_data *tmp;
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

int		ft_give_value(t_stack *stack, int index)
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