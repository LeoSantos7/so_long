/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:52:13 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 08:48:57 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c);
static size_t	get_word_length(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;
	size_t	word_length;

	count = count_words(s, c);
	split = malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && (*s == c))
			s++;
		word_length = get_word_length(s, c);
		split[i] = malloc(word_length + 1);
		if (!split[i])
			return (NULL);
		ft_strlcpy(split[i], s, word_length + 1);
		s += word_length;
		i++;
	}
	split[i] = NULL;
	return (split);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && (*s != c))
			s++;
	}
	return (count);
}

static size_t	get_word_length(const char *s, char c)
{
	char	*word_delimiter;

	word_delimiter = ft_strchr(s, c);
	if (!word_delimiter)
		word_delimiter = ft_strchr(s, '\0');
	return (word_delimiter - s);
}
