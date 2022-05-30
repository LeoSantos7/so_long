/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:27:58 by lesantos          #+#    #+#             */
/*   Updated: 2021/08/31 10:00:32 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (*src++)
			i++;
		return (i);
	}
	while (*src && (i < size - 1))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	while (*src++)
		i++;
	return (i);
}
