/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:10 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/17 18:32:37 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef	struct		s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;

	int				num;
	int				index;
	int				cost;
	int				layer;
}					t_dlist;

typedef struct 		s_stack
{
	t_dlist			*head;
	t_dlist			*tail;
	int				size;
}					t_stack;


/* argurments checker*/
void	ft_arg_check(int argc, char **argv);
void	ft_arg_checker(int argc, char **argv, int index);
void	ft_arg_checker_split(char **argv);

/*split with wc*/

char	**ft_split_wc(char const *s, char c, int *wc);

/* error & free management*/
void	ft_eq(char *msg);
void	*ft_free_tab(char **tab);
void	ft_free(void);

/* arguments parser*/
t_stack	*ft_arg_parser(int argc, char **argv);

/* double linked list utils*/
t_dlist	*ft_dlst_last(t_dlist *lst);
t_dlist	*ft_dlst_first(t_dlist *lst);
void	ft_dlst_clear(t_dlist **lst);
t_dlist	*ft_dlst_new(int data);
void	ft_dlst_add_back(t_dlist **lst, t_dlist *new);
void	ft_dlst_add_front(t_dlist **lst, t_dlist *new);

#endif
