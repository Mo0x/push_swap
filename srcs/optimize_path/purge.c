/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:37:34 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/31 19:50:35 by mgovinda         ###   ########.fr       */
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

void	ft_purge_p(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("pa", tmp->content)) && (!ft_strcmp("pb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
	else if ((!ft_strcmp("pb", tmp->content)) && (!ft_strcmp("pa", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
}

void	ft_purge_s(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("sa", tmp->content)) && (!ft_strcmp("sa", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
	else if ((!ft_strcmp("sb", tmp->content)) && (!ft_strcmp("sb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
}

void	ft_purge_ra(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("ra", tmp->content)) && (!ft_strcmp("rra", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
	else if ((!ft_strcmp("rra", tmp->content)) && (!ft_strcmp("ra", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
}

void	ft_purge_rb(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("rb", tmp->content)) && (!ft_strcmp("rrb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
	else if ((!ft_strcmp("rrb", tmp->content)) && (!ft_strcmp("rb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = NULL;
	}
}

void	ft_path_purge(t_list *ret)
{
	t_list	*tmp;

	tmp = ret->next;
	while (tmp)
	{
		if ((!ft_strcmp("pa", tmp->content) || !ft_strcmp("pb", tmp->content)) && tmp->next)
			ft_purge_p(tmp);
		else if ((!ft_strcmp("sa", tmp->content) || !ft_strcmp("sb", tmp->content)) && tmp->next)
			ft_purge_s(tmp);
		else if ((!ft_strcmp("ra", tmp->content)|| !ft_strcmp("rra", tmp->content)) && tmp->next)
			ft_purge_ra(tmp);
		else if ((!ft_strcmp("rb", tmp->content)|| !ft_strcmp("rrb", tmp->content)) && tmp->next)
			ft_purge_rb(tmp);
		tmp = tmp->next;
	}
}