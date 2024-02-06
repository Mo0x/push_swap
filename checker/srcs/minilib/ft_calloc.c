/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:45:37 by mgovinda          #+#    #+#             */
/*   Updated: 2024/02/06 16:53:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}
