/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:04 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 19:39:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_dlist *stack_a;
	char *ret;

	ret = NULL;
	(void) ret;
	if (argc == 1)
		exit(0);
	ft_arg_checker(argc, argv);
	stack_a = ft_arg_parser(argc, argv);
	//tmp check list

	/*if (argc == 4)
		ret = ft_tinysort(stack_a);
	else if (argc == 6)
		ret = ft_tinysort_v2(stack_a);
	else
		ret = ft_strongsort(stack_a);*/
	int i = 1;
	//t_dlist *tmp;
	while (stack_a)
	{
			ft_printf(1, "%d :%d min = %d max = %d\n", i, stack_a->data->num, stack_a->data->min, stack_a->data->max);
			i++;
			stack_a = stack_a->next;
	}
	stack_a = ft_dlst_first(stack_a);
	ft_dlst_clear(&stack_a);
	return (0);
}