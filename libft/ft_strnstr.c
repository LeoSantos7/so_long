/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:57:59 by lesantos          #+#    #+#             */
/*   Updated: 2021/10/04 06:04:50 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	little_len;

	little_len = ft_strlen(little);
	count = 0;
	while (count + little_len <= len)
	{
		if (!ft_strncmp(big + count, little, little_len))
			return ((char *)(big + count));
		if (big[count + little_len] == '\0')
			return (NULL);
		if (big[count] == '\0')
			return (NULL);
		count++;
	}
	return (NULL);
}
