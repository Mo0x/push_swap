/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:35:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/19 17:14:56 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bigboi_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*secret_stack;

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
	ft_putendl_fd(ft_sa(stack_a), 1);
	ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	ft_putendl_fd(ft_pb(stack_a, stack_b), 1);
	ft_putendl_fd(ft_rra(stack_a), 1);
	ft_putendl_fd(ft_rrr(stack_a, stack_b), 1);
	t_node	*tmp_b =stack_b->head;
	tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "%d :%d\n", tmp->data->index, tmp->data->num);
		tmp = tmp->next;
	}
	while (tmp_b)
	{
		ft_printf(1, "%d :%d\n", tmp_b->data->index, tmp_b->data->num);
		tmp_b = tmp_b->next;
	}
	ft_printf(1, "stack a size = %d, stack b_size = %d", stack_a->size, stack_b->size);
	ft_nodes_clear(&(stack_a->head));
	ft_nodes_clear(&(secret_stack->head));
	free(secret_stack);
	free(stack_a);
}

void	ft_push_swap(t_stack *stack_a)
{
	t_stack *stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_eq("Error malloc");
	stack_b->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	if (stack_a->size == 3)
		ft_tiny_sort(stack_a);
	else if (stack_a->size == 5)
		ft_baby_sort(stack_a, stack_b);
	else
		ft_bigboi_sort(stack_a, stack_b);
	ft_nodes_clear(&(stack_b->head));
	free(stack_b);
}