/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:26:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 17:03:18 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlst_cleanup(**lst)
{
	t_dlist	*current;

	if (!lst)
		return ;
	while (*lst)
	{
		current = *lst
		*lst = current->next;
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

