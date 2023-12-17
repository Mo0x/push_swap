/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:14:45 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/17 19:57:07 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_average(t_stack stack)
{
	long long	sum;
	t_node		*tmp;
	long long	ret;

	sum = 0;
	tmp = stack->head;
	while (tmp)
	{
		sum += tmp->data->num;
		tmp = tmp->next;
	}
	ret = sum / stack->size;
	return (int)(ret);
}

t_stack *ft_quick_sort(t_stack stack_a)
{
	(void) stack_a;	
}