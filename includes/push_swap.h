/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:10 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/15 19:34:38 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_data
{
	int	num;
	int	index;
	int	min;
	int max;
	int	top;
	int bot;
}					t_data;

typedef	struct		s_dlist
{
	t_data			*data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;


/* argurments checker*/
void	ft_arg_checker(int argc, char **argv);

/* error management*/
void	ft_eq(char *msg);

/* arguments parser*/
t_dlist	*ft_arg_parser(int argc, char **argv);

/* double linked list utils*/
t_dlist	*ft_dlst_last(t_dlist *lst);
t_dlist	*ft_dlst_first(t_dlist *lst);
void	ft_dlst_clear(t_dlist **lst);
t_dlist	*ft_dlstnew(int data);
void	ft_dlst_add_back(t_dlist **lst, t_dlist *new);
void	ft_dlst_add_front(t_dlist **lst, t_dlist *new);
#endif
