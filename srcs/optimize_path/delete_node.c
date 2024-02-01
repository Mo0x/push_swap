/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:04:33 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/01 16:23:08 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_node(t_list **head, t_list *to_delete)
{
	t_list	*tmp;
	t_list	*current;

	if ((*head) == to_delete)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			if (current->next == to_delete)
			{
				tmp = current->next;
				current->next = current->next->next;
				free(tmp);
				break ;
			}
			else
				current = current->next;
		}
	}
}
