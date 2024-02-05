/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:45:43 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/05 13:46:11 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	if (!ret)
		return (NULL);
	while (++i < (int)ft_strlen(s))
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

static char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char				*ret;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && s[start])
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*ft_recycle(int fd, char **garbage)
{
	char	*ret;
	char	*trashbag;
	int		i;

	i = 0;
	if (!garbage[fd])
		return (NULL);
	while (garbage[fd][i] && garbage[fd][i] != '\n')
		i++;
	if (garbage[fd][i] == '\n')
		i++;
	ret = ft_substr(garbage[fd], 0, i);
	trashbag = ft_substr(garbage[fd], i, ft_strlen(&garbage[fd][i]));
	free(garbage[fd]);
	garbage[fd] = trashbag;
	if (!ret || !trashbag || ft_strlen(ret) == 0)
	{
		free(garbage[fd]);
		free(ret);
		garbage[fd] = NULL;
		return (NULL);
	}
	return (ret);
}

static char	*ft_read_trash(int fd, char **garbage, char *trashbag)
{
	char	*second_trashbag;
	int		byte_read;

	byte_read = 1;
	while (byte_read >= 0)
	{
		ft_memset(trashbag, 0, BUFFER_SIZE + 1);
		byte_read = read(fd, trashbag, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(garbage[fd]);
			return (NULL);
		}
		if (!garbage[fd])
			garbage[fd] = ft_strdup(trashbag);
		else
		{
			second_trashbag = ft_strjoin(garbage[fd], trashbag);
			free(garbage[fd]);
			garbage[fd] = second_trashbag;
		}
		if (garbage[fd] && (byte_read == 0 || ft_strchr(garbage[fd], '\n')))
			return (garbage[fd]);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*garbage[1024];
	char		*ret;
	char		*trashbag;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	trashbag = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!trashbag)
		return (NULL);
	garbage[fd] = ft_read_trash(fd, garbage, trashbag);
	free(trashbag);
	if (!garbage[fd])
		return (NULL);
	ret = ft_recycle(fd, garbage);
	return (ret);
}