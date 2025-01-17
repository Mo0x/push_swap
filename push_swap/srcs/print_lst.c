/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:18:17 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/01 17:34:54 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *ret)
{
	t_list *head;

	head = ret;
	ret = ret->next;
	while (ret)
	{
		if (ret->content != NULL)
			ft_printf(1, "%s\n", ret->content);
		ret = ret->next;
	}
	ft_lstclear(&head, free);
}