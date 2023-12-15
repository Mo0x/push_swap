/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:10 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 16:24:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef	struct s_dlist
{
	int		num;
	int 	index;
	int		min;
	int		max;
	t_dlist	*next;
	t_dlist	*prev;
}			t_dlist;

void	ft_arg_checker(int argc, char **argv);
void	ft_eq(char *msg);

#endif