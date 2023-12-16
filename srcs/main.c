/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:04 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/16 19:10:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*ret;

	ret = NULL;
	(void) ret;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
		ft_arg_checker_split(argv);
	else
		ft_arg_checker(argc, argv, 1);
	stack_a = ft_arg_parser(argc, argv);
	//tmp check list

	/*if (stack_a->size = 3)
		ret = ft_tinysort(stack_a);
	else if (stack_a->size == 5)
		ret = ft_tinysort_v2(stack_a);
	else
		ret = ft_push_swap(stack_a);*/
	int i = 1;
	t_dlist *tmp = stack_a->head;
	while (tmp)
	{
			ft_printf(1, "%d :%d\n", i, tmp->num);
			i++;
			tmp = tmp->next;
	}
	ft_dlst_clear(&(stack_a->head));
	free(stack_a);
	return (0);
}