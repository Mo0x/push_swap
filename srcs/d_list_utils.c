/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 17:38:40 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dlst_cleanup(**lst)
{
	t_dlist	*current;
	t_dlist	*prv;

	if (!lst)
		return ;
	prv = (*lst)->prev;
	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		free(current);
	}
	while(prv)
	{
		current = prv;
		prv = current->prev;
		free(current);
	}
	lst = NULL;
}

t_dlist	*ft_dlstnew(int data)
{
	t_dlist	ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->num = data;
	ret->next = NULL;
	ret->prev = NULL;
	ret->index = -1;
	ret->min = 0;
	ret->max = 0;
	return (ret)
}

void	ft_dlstadd_back(t_list **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;	
	}
}
