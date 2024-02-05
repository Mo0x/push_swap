/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:42:29 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 14:15:24 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	char	*line;

	if (ac == 1)
		return (0);
	ft_arg_init(ac, av);
	a = ft_arg_parser(ac, av);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_parser(a, b, line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_is_sorted(a) && a->size == a->max_size)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ft_nodes_clear(&(a->head));
	ft_nodes_clear(&(b->head));
	free(a);
	free(b);
}