/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:45:23 by mgovinda          #+#    #+#             */
/*   Updated: 2023/12/19 15:09:31 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen_till(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (*s && *s != c)
	{
		ret++;
		s++;
	}
	return (ret);
}

static int	ft_countwords(char const *s, char c)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			ret++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (ret);
}

static char	*ft_strdup_word(char const *s, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen_till(s, c) + 1));
	if (!ret)
		return (NULL);
	while (i < ft_strlen_till(s, c))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split_wc(char const *s, char c, int *wc)
{
	char	**ret;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	*wc = ft_countwords(s, c);
	ret = ft_calloc(sizeof(char *), (*wc + 1));
	if (!ret)
		return (NULL);
	while (++i < *wc)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			ret[i] = ft_strdup_word(s, c);
			if (!ret[i])
				return (NULL);
			while (*s && *s != c)
				s++;
		}
	}
	return (ret);
}