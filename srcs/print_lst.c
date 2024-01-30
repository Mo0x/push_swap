/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:18:17 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/30 20:24:25 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *ret)
{
	t_list *tmp;

	tmp = tmp->next;
	while (tmp)
	{
		ft_printf(1, "%s\n", tmp->content);
		tmp->next;
	}
}