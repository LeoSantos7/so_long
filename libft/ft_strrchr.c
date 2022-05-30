/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:19:14 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/02 21:46:05 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;

	if ((unsigned char) c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	r = NULL;
	while (*s)
	{
		if (*s == (unsigned char) c)
			r = s;
		s++;
	}
	return ((char *) r);
}
