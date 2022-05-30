/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 05:59:06 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 10:45:19 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	size_t				i;

	src = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char) c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
