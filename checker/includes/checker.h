/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 15:43:19 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 4
# include <fcntl.h>
# include <unistd.h>

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

void	*ft_memset(void *s, int c, size_t n);
void	ft_parser(t_stack *a, t_stack *b, char *line);
void	ft_error(t_stack *a, t_stack *b);
t_stack	*ft_init_b(t_stack *a);

/*GNL*/
char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(char *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

/* instructions*/
char	*ft_sa(t_stack *stack);
char	*ft_sb(t_stack *stack);
char	*ft_ss(t_stack *stack_a, t_stack *stack_b);
char	*ft_pa(t_stack *stack_a, t_stack *stack_b);
char	*ft_pb(t_stack *stack_a, t_stack *stack_b);
char	*ft_ra(t_stack *stack_a);
char	*ft_rb(t_stack *stack_b);
char	*ft_rr(t_stack *stack_a, t_stack *stack_b);
char	*ft_rra(t_stack *stack);
char	*ft_rrb(t_stack *stack);
char	*ft_rrr(t_stack *stack_a, t_stack *stack_b);

#endif