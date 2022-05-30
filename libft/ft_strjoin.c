/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:18:21 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 12:59:42 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat_str = malloc(s1_len + s2_len + 1);
	if (!concat_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		concat_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		concat_str[s1_len + i] = s2[i];
		i++;
	}
	concat_str[s1_len + i] = '\0';
	return (concat_str);
}
