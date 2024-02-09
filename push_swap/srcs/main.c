/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:04 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/09 15:29:24 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0 = 3700;
https://medium.com/@julien-ctx/push-swap-an-easy-and-efficient-algorithm-to-sort-numbers-4b7049c2639a = secret stack;
*/


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_list	*ret;

	ft_arg_init(argc, argv);
	stack_a = ft_arg_parser(argc, argv);
	ret = ft_lstnew("init");
	ft_push_swap(stack_a, &ret);
	ft_optimize(ret);
	ft_printlst(ret);
	ft_nodes_clear(&(stack_a->head));
	free(stack_a);
	return (0);
}