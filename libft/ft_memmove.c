/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:52:15 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 13:00:41 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char_ptr;
	const unsigned char	*src_char_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_char_ptr = dest;
	src_char_ptr = (const unsigned char *) src;
	if (src < dest)
	{
		dest_char_ptr += n;
		src_char_ptr += n;
		while (n--)
		{
			*--dest_char_ptr = *--src_char_ptr;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
