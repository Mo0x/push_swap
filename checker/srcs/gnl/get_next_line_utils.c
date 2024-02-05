/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:39:41 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 15:39:57 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*ret;
	size_t	i;

	ret = s;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = c;
		i++;
		s++;
	}
	return (ret);
}

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	y;

	i = ft_strlen(s1);
	y = 0;
	while (s2[y])
	{
		s1[i + y] = s2[y];
		y++;
	}
	s1[i + y] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		tot_length;

	if (!s1 || !s2)
		return (NULL);
	tot_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * tot_length);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, tot_length);
	ret = ft_strcat(ret, s1);
	ret = ft_strcat(ret, s2);
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0 && !(*(s + i)))
		return ((char *)(s + i));
	return (NULL);
}