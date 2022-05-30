/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:23:26 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 13:00:49 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_char_ptr;
	const unsigned char	*src_char_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_char_ptr = dest;
	src_char_ptr = (const unsigned char *) src;
	while (i < n)
	{
		dest_char_ptr[i] = src_char_ptr[i];
		i++;
	}
	return (dest);
}
