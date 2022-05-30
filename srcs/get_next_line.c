/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:05 by lesantos          #+#    #+#             */
/*   Updated: 2022/02/09 13:36:14 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_num;
	int			endl_found;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	endl_found = ft_append_line(&line, buffer);
	while (!endl_found)
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num <= 0)
			break ;
		if (read_num < BUFFER_SIZE)
			buffer[read_num] = '\0';
		endl_found = ft_append_line(&line, buffer);
	}
	return (line);
}

void	ft_strncpy(char *dst, char *src, unsigned int len)
{
	while (len-- && *src)
		*dst++ = *src++;
	*dst = '\0';
}

size_t	ft_linelen(char *s, int *endl_found)
{
	size_t	len;

	len = 0;
	if (endl_found)
		*endl_found = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		if (*s++ == '\n')
		{
			*endl_found = 1;
			break ;
		}
	}
	return (len);
}

int	ft_append_line(char **line, char *buffer)
{
	size_t	line_len;
	size_t	buf_len;
	char	*new_line;
	int		endl_found;

	buf_len = ft_linelen(buffer, &endl_found);
	if (!buf_len)
		return (0);
	line_len = ft_linelen(*line, NULL);
	new_line = malloc(line_len + buf_len + 1);
	ft_strncpy(new_line, *line, line_len);
	ft_strncpy(new_line + line_len, buffer, buf_len);
	free(*line);
	*line = new_line;
	ft_strncpy(buffer, buffer + buf_len, BUFFER_SIZE);
	return (endl_found);
}
