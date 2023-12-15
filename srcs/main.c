/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:04 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 16:00:43 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	//t_struct binary_or_chained_list stack_a
	char *ret;

	if (argc == 1)
		exit(0);
	arg_checker(argc, argv);
	stack_a = ft_arg_parser(argc, argv);
	if (argc == 4)
		ret = ft_tinysort(stack_a);
	else if (argc == 6)
		ret = ft_tinysort_v2(stack_a);
	else
		ret = ft_strongsort(stack_a);
	ft_printf(1, "%s", ret);
	return (0);
}