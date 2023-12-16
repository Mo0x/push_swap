/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/16 17:13:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlst_last(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dlist *ft_dlst_first(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev; 
	return (lst);
}

void	ft_dlst_clear(t_dlist **lst)
{
	t_dlist	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = (*lst)->next;
		free(current);
	}
	lst = NULL;
}

t_dlist	*ft_dls_tnew(int content)
{
	t_dlist	*ret;

	ret = malloc(sizeof(t_dlist));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->prev = NULL;
	ret->num = content;
	ret->index = -1;
	ret->cost = -1;
	return (ret);
}

void	ft_dlst_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_dlst_last(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	ft_dlst_add_front(t_dlist **lst, t_dlist *new)
{
	t_dlist *first;
	
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