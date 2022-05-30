/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:17:04 by lesantos          #+#    #+#             */
/*   Updated: 2021/10/04 05:12:34 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s1_len;
	char const	*last_ptr;
	char		*r;

	while (*s1)
	{
		if (!char_in_set(*s1, set))
			break ;
		s1++;
	}
	s1_len = ft_strlen(s1);
	last_ptr = s1 + s1_len - 1;
	while (s1_len--)
	{
		if (!char_in_set(*last_ptr, set))
			break ;
		last_ptr--;
	}
	r = malloc(last_ptr - s1 + 2);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, last_ptr - s1 + 2);
	return (r);
}
