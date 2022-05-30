/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:35:03 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/02 10:07:53 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*dst && len < size)
	{
		len++;
		dst++;
	}
	if (size && len < size)
	{
		while (*src && (len < size - 1))
		{
			*dst++ = *src++;
			len++;
		}
		*dst = '\0';
	}
	while (*src++)
		len++;
	return (len);
}
