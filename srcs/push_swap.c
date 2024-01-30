/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:35:55 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/30 18:46:35 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end_rotate(t_stack *stack_a)
{
	t_node	*first;
	int		ra;

	first = stack_a->head;
	ra = 0;
	while (first->data->s_index != 0)
		first = first->next;
	if (first->data->index < stack_a->max_size)
		ra = 1;
	while (!ft_is_sorted(stack_a))
	{
		if (ra)
			ft_putendl_fd(ft_ra(stack_a), 1);
		else
			ft_putendl_fd(ft_rra(stack_a), 1);
	}
}

void	ft_bigboi_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*secret_stack;
	int		is_layered;

	secret_stack = ft_quick_sort_init(stack_a);
	is_layered = 0;
	if (!secret_stack)
		exit(1);
	ft_indexing(stack_a, secret_stack);
	if (stack_a->max_size > 99)
		is_layered = ft_layering_init(stack_a);
	t_node *tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "max size =%d  stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", stack_a->max_size , tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost);
		tmp = tmp->next;
	}
	t_node *tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(1, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost);
		tmp2 = tmp2->next;
	}
	sleep(10);
	ft_push_back(stack_a, stack_b, is_layered);

	ft_end_rotate(stack_a);
	/*tmp = stack_a->head;
	while (tmp)
	{
		ft_printf(1, "stack a i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp->data->index,tmp->data->s_index, tmp->data->num, tmp->data->layer, tmp->data->cost);
		tmp = tmp->next;
	}
	tmp2 = stack_b->head;
	while (tmp2)
	{
		ft_printf(1, "stack b i = %d, s_i = %d :%d, layer = %d cost = %d \n", tmp2->data->index,tmp2->data->s_index, tmp2->data->num, tmp2->data->layer, tmp2->data->cost);
		tmp2 = tmp2->next;
	}*/
	ft_nodes_clear(&(secret_stack->head));
	free(secret_stack);
}

void	ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	if (ft_is_sorted(stack_a))
		return ;
	stack_a->max_size = stack_a->size;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_eq("Error malloc");
	stack_b->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->max_size = stack_a->size;
	if (stack_a->max_size == 2)
		ft_micro_sort(stack_a);
	else if (stack_a->max_size == 3)
		ft_tiny_sort(stack_a);
	else if (stack_a->max_size == 5)
		ft_baby_sort(stack_a, stack_b);
	else
		ft_bigboi_sort(stack_a, stack_b);
	ft_nodes_clear(&(stack_b->head));
	free(stack_b);
}
