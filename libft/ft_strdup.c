/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:12:33 by lesantos          #+#    #+#             */
/*   Updated: 2021/10/04 06:13:31 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*cpy;

	len = 0;
	while (s[len])
		len++;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (cpy - len);
}
