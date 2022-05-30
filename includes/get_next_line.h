/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:55:30 by lesantos          #+#    #+#             */
/*   Updated: 2022/02/09 13:37:17 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	ft_strncpy(char *dst, char *src, unsigned int len);
size_t	ft_linelen(char *s, int *endl_found);
int		ft_append_line(char **line, char *buffer);
#endif
