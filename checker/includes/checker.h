/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/06 18:40:37 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 4
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_data
{
	int				num;
	int				index;
	int				cost_a;
	int				cost_b;
	int				layer;
	int				s_index;
}					t_data;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	t_data			*data;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	int				max_size;
}					t_stack;

void			*ft_memset(void *s, int c, size_t n);
void			ft_parser(t_stack *a, t_stack *b, char *line);
void			ft_error(t_stack *a, t_stack *b);
t_stack			*ft_init_b(t_stack *a);

/*GNL*/
char			*get_next_line(int fd);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strlen(char *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);

/* instructions*/
char			*ft_sa(t_stack *stack);
char			*ft_sb(t_stack *stack);
char			*ft_ss(t_stack *stack_a, t_stack *stack_b);
char			*ft_pa(t_stack *stack_a, t_stack *stack_b);
char			*ft_pb(t_stack *stack_a, t_stack *stack_b);
char			*ft_ra(t_stack *stack_a);
char			*ft_rb(t_stack *stack_b);
char			*ft_rr(t_stack *stack_a, t_stack *stack_b);
char			*ft_rra(t_stack *stack);
char			*ft_rrb(t_stack *stack);
char			*ft_rrr(t_stack *stack_a, t_stack *stack_b);

/* linked list*/
void			ft_node_del(t_stack *stack, t_node *to_del);
void			ft_node_add_front(t_stack *lst, t_node *new);
t_node			*ft_node_last(t_node *lst);
t_node			*ft_node_first(t_node *lst);
void			ft_swap_nodes(t_node *a, t_node *b);
t_node			*ft_select_node(t_stack *stack, int index);
t_node			*ft_node_dup(t_node *node);
void			ft_copy_data(t_data *og, t_data *copy);
t_node			*ft_node_new(int content);
void			ft_node_add_back(t_node **lst, t_node *new);
void			ft_fix_index(t_node *to_fix);
void			ft_nodes_clear(t_node **lst);
int				ft_is_sorted(t_stack *stack);

/*argcheck*/
void			ft_arg_init(int argc, char **argv);
void			ft_arg_checker_split(char **argv);
void			ft_eq(char *msg);
void			ft_free_tab(char **tab);
t_stack			*ft_arg_parser(int argc, char **argv);

/*minilib*/
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *nptr);
long long		ft_atoll(const char *nptr);
int				ft_isdigit(int c);
int				ft_printf(int fd, const char *fmt, ...);
int				ft_printpc(int fd);
unsigned int	ft_unsigned(int fd, unsigned int nb);
int				ft_pointer(int fd, unsigned long addr);
int				ft_hexa(int fd, unsigned int nb, char format);
int				ft_number(int fd, int nb);
int				ft_string(int fd, char *string);
char			**ft_split_wc(char const *s, char c, int *wc);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif