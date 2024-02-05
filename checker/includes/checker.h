/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:36:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 14:28:02 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 4
# include <fcntl.h>
# include <unistd.h>
# include "../../push_swap/includes/push_swap.h"

void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(char *s);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
void	ft_parser(t_stack *a, t_stack *b, char *line);

#endif