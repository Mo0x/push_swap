/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:37:34 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/01 16:02:00 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa + pb
sa + sa
sb + sb
ra + rra
rb + rrb
*/

void	ft_purge_p(t_list *tmp, t_list **head)
{
	if ((!ft_strcmp("pa", tmp->content)) && (!ft_strcmp("pb", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
	else if ((!ft_strcmp("pb", tmp->content)) && (!ft_strcmp("pa", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
}

void	ft_purge_s(t_list *tmp, t_list **head)
{
	if ((!ft_strcmp("sa", tmp->content)) && (!ft_strcmp("sa", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
	else if ((!ft_strcmp("sb", tmp->content)) && (!ft_strcmp("sb", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
}

void	ft_purge_ra(t_list *tmp, t_list **head)
{
	if ((!ft_strcmp("ra", tmp->content)) && (!ft_strcmp("rra", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
	else if ((!ft_strcmp("rra", tmp->content)) && (!ft_strcmp("ra", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);	
	}
}

void	ft_purge_rb(t_list *tmp, t_list **head)
{
	if ((!ft_strcmp("rb", tmp->content)) && (!ft_strcmp("rrb", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
	else if ((!ft_strcmp("rrb", tmp->content)) && (!ft_strcmp("rb", tmp->next->content)))
	{
		ft_delete_node(head, tmp->next);
		ft_delete_node(head, tmp);
	}
}

void	ft_path_purge(t_list *ret)
{
	t_list	*tmp;
	t_list	*head;

	head = ret;
	tmp = ret;
	while (tmp)
	{
		if (tmp->next)
		{	
			if ((!ft_strcmp("pa", tmp->next->content) || !ft_strcmp("pb", tmp->next->content)) && tmp->next->next)
				ft_purge_p(tmp->next, &head);
			else if ((!ft_strcmp("sa", tmp->next->content) || !ft_strcmp("sb", tmp->next->content)) && tmp->next->next)
				ft_purge_s(tmp->next, &head);
			else if ((!ft_strcmp("ra", tmp->next->content)|| !ft_strcmp("rra", tmp->next->content)) && tmp->next->next)
				ft_purge_ra(tmp->next, &head);
			else if ((!ft_strcmp("rb", tmp->next->content)|| !ft_strcmp("rrb", tmp->next->content)) && tmp->next->next)
				ft_purge_rb(tmp->next, &head);
		}
		tmp = tmp->next;
	}
}