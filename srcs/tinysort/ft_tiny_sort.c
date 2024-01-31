/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:11:51 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/31 17:50:35 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_micro_sort(t_stack *stack, t_list **ret)
{
	if (!ft_is_sorted(stack))
			ft_lstadd_back(ret, ft_lstnew(ft_sa(stack)));
}

void	ft_baby_sort(t_stack *stack_a, t_stack *stack_b, t_list **ret)
{
	t_stack	*s;

	s = ft_quick_sort_init(stack_a);
	ft_indexing(stack_a, s);
	while (stack_a->size > 3)
		ft_lstadd_back(ret, ft_lstnew(ft_pb(stack_a, stack_b)));
	ft_tiny_sort(stack_a, ret);
	while (stack_b->head)
	{
		ft_rotate_a(stack_a, stack_b->head, ret);
		ft_lstadd_back(ret, ft_lstnew(ft_pa(stack_a, stack_b)));
	}
	ft_end_rotate(stack_a, ret);
}

t_node	*biggest_node(t_stack *stack)
{
	int		bigger;
	t_node	*tmp;
	t_node	*ret;

	if (stack == NULL)
		return (NULL);
	tmp = stack->head;
	bigger = INT_MIN;
	while (tmp)
	{
		if (tmp->data->num > bigger)
		{	
			bigger = tmp->data->num;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_tiny_sort(t_stack *stack_a, t_list **ret)
{
	t_node	*bigger;

	bigger = biggest_node(stack_a);
	if (stack_a->head == bigger)
		ft_lstadd_back(ret, ft_lstnew(ft_ra(stack_a)));
	else if (stack_a->head->next == bigger)
		ft_lstadd_back(ret, ft_lstnew(ft_rra(stack_a)));
	if (stack_a->head->data->num > \
		stack_a->head->next->data->num)
		ft_lstadd_back(ret, ft_lstnew(ft_sa(stack_a)));
}