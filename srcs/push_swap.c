/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:35:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/18 17:22:07 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bigboi_sort(t_stack *stack_a)
{
	t_stack	*secret_stack;
	//t_stack	*stack_b;
	secret_stack = ft_quick_sort_init(stack_a);
	if (!secret_stack)
		exit(1);
	
	ft_indexing(stack_a, secret_stack);
	/*ft_layering(stack_a, stack_b);
	ft_push_back(stack_a, stack_b);*/

	t_node *tmp = stack_a->head;
	while (tmp)
	{
			ft_printf(1, "i = %d, s_i = %d :%d\n", tmp->data->index,tmp->data->s_index, tmp->data->num);
			tmp = tmp->next;
	}
	t_node *new_node = ft_node_new(404);
	ft_node_add_front(stack_a, new_node);
	tmp = stack_a->head;
	while (tmp)
	{
			ft_printf(1, "%d :%d\n", tmp->data->index, tmp->data->num);
			tmp = tmp->next;
	}
	ft_nodes_clear(&(stack_a->head));
	ft_nodes_clear(&(secret_stack->head));
	free(secret_stack);
	free(stack_a);
}

void	ft_push_swap(t_stack *stack_a)
{
	if (stack_a->size == 3)
		ft_tiny_sort(stack_a);
	else if (stack_a->size == 5)
		ft_baby_sort(stack_a);
	else
		ft_bigboi_sort(stack_a);
}