/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:10 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/19 15:32:11 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct		s_data
{
	int				num;
	int				index;
	int				cost;
	int				layer;
	int				s_index;
}					t_data;

typedef	struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	t_data			*data;
}					t_node;

typedef struct 		s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;


/* argurments checker*/
void	ft_arg_init(int argc, char **argv);
void	ft_arg_checker(int argc, char **argv, int index);
void	ft_arg_checker_split(char **argv);

/*split with wc*/

char	**ft_split_wc(char const *s, char c, int *wc);

/* error & free management*/
void	ft_eq(char *msg);
void	ft_free_tab(char **tab);
void	ft_free(t_stack stack);

/* arguments parser*/
t_stack	*ft_arg_parser(int argc, char **argv);

/* sorting*/
void	ft_push_swap(t_stack *stack_a);
void	ft_tiny_sort(t_stack *stack_a);
void	ft_baby_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_bigboi_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_quick_sort(t_stack *stack_a, int min, int max);
t_stack	*ft_quick_sort_init(t_stack *stack_a);
void	ft_indexing(t_stack *stack_to_index, t_stack *ref);

/*instructions*/

char	*ft_sa(t_stack *stack);
char	*ft_sb(t_stack *stack);
char	*ft_ss(t_stack *stack_a, t_stack *stack_b);
char	*ft_pa(t_stack *stack_a, t_stack *stack_b);
char	*ft_pb(t_stack *stack_a, t_stack *stack_b);

/* stack double linked list utils*/
void	ft_node_del(t_stack *stack, t_node *to_del);
t_node	*ft_node_last(t_node *lst);
t_node	*ft_node_first(t_node *lst);
void	ft_nodes_clear(t_node **lst);
t_node	*ft_node_new(int data);
void	ft_node_add_back(t_node **lst, t_node *new);
void	ft_node_add_front(t_stack *lst, t_node *new);
t_stack	*ft_stack_dup(t_stack *stack);
t_node	*ft_select_node(t_stack *stack, int index);
int		ft_give_value(t_stack *stack, int index);
void	ft_swap_nodes(t_node *a, t_node *b);
t_node	*ft_get_node(t_stack *stack, int value);
t_node	*ft_node_dup(t_node *node);

#endif
