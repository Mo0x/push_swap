/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:27:45 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/01 15:36:14 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
merge
sa + sb = ss
ra + rb = rr;
rra +rrb = rrr 

divide

pa + pb
sa + sa
ra + rra
*/
void	ft_merge_ss(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("sa", tmp->content)) && (!ft_strcmp("sb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "ss";
	}
	else if ((!ft_strcmp("sb", tmp->content)) && (!ft_strcmp("sa", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "ss";
	}
}

void	ft_merge_rr(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next;
	if ((!ft_strcmp("ra", tmp->content)) && (!ft_strcmp("rb", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "rr";
	}
	else if ((!ft_strcmp("rb", tmp->content)) && (!ft_strcmp("ra", tmp->next->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "rr";
	}
}

void	ft_merge_rrr(t_list *tmp)
{
	t_list	*lst;

	lst = tmp->next; 
	if ((!ft_strcmp("rra", tmp->content)) && (!ft_strcmp("rrb", lst->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "rrr";
	}
	else if ((!ft_strcmp("rrb", tmp->content)) && (!ft_strcmp("rra", lst->content)))
	{
		tmp->next = lst->next;
		ft_lstdelone(lst, free);
		tmp->content = "rrr";
	}
}

void	ft_path_merge(t_list *ret)
{
	t_list	*tmp;

	tmp = ret->next;
	while (tmp)
	{
		if ((!ft_strcmp("sa", tmp->content) || !ft_strcmp("sb", tmp->content)) && tmp->next)
			ft_merge_ss(tmp);
		else if ((!ft_strcmp("ra", tmp->content) || !ft_strcmp("rb", tmp->content)) && tmp->next)
			ft_merge_rr(tmp);
		else if ((!ft_strcmp("rra", tmp->content)|| !ft_strcmp("rrb", tmp->content)) && tmp->next)
			ft_merge_rrr(tmp);
		tmp = tmp->next;
	}
}

void ft_optimize(t_list *ret)
{
		ft_path_merge(ret);
		ft_path_purge(ret);
}
