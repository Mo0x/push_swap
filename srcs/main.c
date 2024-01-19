/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:04 by mgovinda          #+#    #+#             */
/*   Updated: 2024/01/19 18:08:36 by mgovinda         ###   ########.fr       */
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
	//char	*ret;

	ft_arg_init(argc, argv);
	stack_a = ft_arg_parser(argc, argv);
	ft_push_swap(stack_a);
	//ft_print_res(ret);
	//ft_free(stack_a);
	//return (0);

	//tmp check list

	
	/*int i = 1;
	t_node *tmp = stack_a->head;
	while (tmp)
	{
			ft_printf(1, "%d :%d\n", tmp->data->index, tmp->data->num);
			i++;
			tmp = tmp->next;
	}

	ft_nodes_clear(&(stack_a->head));
	free(stack_a);*/
	return (0);
}